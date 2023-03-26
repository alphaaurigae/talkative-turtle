#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>

#include "input_parser.hpp"
#include "pipe_handler.hpp"
#include "input_handler.hpp"
#include "help_printer.hpp"

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;



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