#include "pipe_handler.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "input_parser.hpp"

void handle_pipe_input() {
    std::string input;
    getline(std::cin, input);
    std::vector<std::string> args = parse_input(input);

    for (std::string arg : args) {
        std::cout << arg << std::endl;
    }
}