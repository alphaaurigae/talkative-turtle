#include "help_printer.hpp"

#include <iostream>

void print_help() {
    std::cout << "Usage: program [OPTION]\n\n";
    std::cout << "Options:\n";
    std::cout << "-p\t\tRead input from a pipe\n";
    std::cout << "-i\t\tRead input from command line arguments\n";
    std::cout << "-h\t\tPrint help menu\n";
}