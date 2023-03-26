#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

vector<string> parse_input(string input) {
    vector<string> result;
    string current = "";
    bool in_quotes = false;

    for (char c : input) {
        if (c == '\"') {
            in_quotes = !in_quotes;
        } else if (c == ' ' && !in_quotes) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}

void handle_pipe_input() {
    string input;
    getline(std::cin, input);
    vector<string> args = parse_input(input);

    for (string arg : args) {
        cout << arg << endl;
    }
}

void handle_entered_input(const string& input) {

    if (input.empty()) {
        cout << "-i argument defined but no input given" << endl;
        return;
    }

    vector<string> args = parse_input(input);

    for (string arg : args) {
        cout << arg << endl;
    }
}

void print_help() {
    cout << "Usage: program [OPTION]\n\n";
    cout << "Options:\n";
    cout << "-p\t\tRead input from a pipe\n";
    cout << "-i\t\tRead input from command line arguments\n";
    cout << "-h\t\tPrint help menu\n";
}

int main(int argc, char* argv[]) {
    try {

        // Define program options
        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "Print help menu")
            ("pipe,p", "Read input from a pipe")
            ("input,i", boost::program_options::value<string>(), "Read input from command line arguments");

        // Parse command line arguments
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        // Check for valid options and execute corresponding functions
        if (vm.count("help")) {
            print_help();
        } else if (vm.count("pipe") && vm.count("input")) {
            cout << "Invalid arguments. Cannot use both -p and -i options together." << endl;
        } else if (vm.count("pipe")) {
            handle_pipe_input();
        } else if (vm.count("input")) {
            handle_entered_input(vm["input"].as<string>());
        } else {
            cout << "Invalid arguments. Use -h option to display help menu." << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}