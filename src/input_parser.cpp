#include "input_parser.hpp"

#include <string>
#include <vector>

std::vector<std::string> parse_input(std::string input) {
    std::vector<std::string> result;
    std::string current = "";
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