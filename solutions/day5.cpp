#include <iostream>
#include <fstream>
#include <regex>
#include "Storage.h"


void day5part1() {
    std::string line;
    std::ifstream Day6Input("../inputs/day5.txt");
    int max_line_number = 0, i = 0;
    const std::regex e(" 1.*");
    while (getline(Day6Input, line)) {
        if (regex_match(line, e)) {
            max_line_number = i;
            break;
        }
        i++;
    }
    Day6Input.clear();
    Day6Input.seekg(0);
    std::vector<std::string> stacks_layout;
    int j = 0;
    while (j < max_line_number) {
        getline(Day6Input, line);
        stacks_layout.push_back(line);
        j++;
    }
    Storage stor = Storage(stacks_layout);
    getline(Day6Input, line);
    getline(Day6Input, line);
    while (getline(Day6Input, line)) {
        stor.rearrange(
                std::stoi(line.substr(line.find(" from ") + 6)),
                std::stoi(line.substr(line.find(" to ") + 4)),
                std::stoi(line.substr(line.find("move ") + 5))
        );
    }
    std::cout << "Day 5 part 1: " << stor.get_top_crates() << std::endl;
}

void day5part2() {
    std::string line;
    std::ifstream Day6Input("../inputs/day5.txt");
    while (getline(Day6Input, line)) {
    }
    std::cout << "Day 5 part 2: " << std::endl;
}
