#include <string>
#include <fstream>
#include <iostream>
#include "Rope.h"

void day9part1() {
    std::string line;
    std::ifstream Day9Input("../inputs/day9.txt");
    Rope rope = Rope(2);
    while (getline(Day9Input, line)) {
        rope.move_head(line[0], std::stoi(line.substr(2)));
    }
    Day9Input.close();
    std::cout << "Day 9 part 1: " << rope.get_last()->get_visited().size() << std::endl;
}

void day9part2() {
    std::string line;
    std::ifstream Day9Input("../inputs/day9.txt");
    Rope rope = Rope(10);
    while (getline(Day9Input, line)) {
        rope.move_head(line[0], std::stoi(line.substr(2)));
    }
    Day9Input.close();
    std::cout << "Day 9 part 2: " << rope.get_last()->get_visited().size() << std::endl;
}
