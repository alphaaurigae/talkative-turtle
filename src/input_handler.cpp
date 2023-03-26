#include "input_handler.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "input_parser.hpp"

void handle_entered_input(const std::string& input) {

    if (input.empty()) {
        std::cout << "-i argument defined but no input given" << std::endl;
        return;
    }

    std::vector<std::string> args = parse_input(input);

    for (std::string arg : args) {
        std::cout << arg << std::endl;
    }
}