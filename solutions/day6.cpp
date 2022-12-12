#include <string>
#include <fstream>
#include <iostream>

void day6part1() {
    std::string line;
    std::ifstream Day6Input("../inputs/day6.txt");
    while (getline(Day6Input, line)) {
        for (int i = 0; i < line.size() - 4; ++i) {
            if (line[i] != line[i + 1] && line[i] != line[i + 2] && line[i] != line[i + 3] && line[i + 2] != line[i + 1] && line[i + 3] != line[i + 1] && line[i + 3] != line[i + 2]) {
                std::cout << "Day 6 part 1: " << i + 4 << std::endl;
                return;
            }
        }
    }
}

void day6part2() {
    std::string line;
    std::ifstream Day6Input("../inputs/day6.txt");
    while (getline(Day6Input, line)) {
        for (int i = 0; i < line.size() - 14; ++i) {
            std::string so_far;
            for (int j = 0; j < 14; ++j) {
                if (so_far.find(line[i + j]) != std::string::npos) {
                    break;
                }
                so_far += (line[i + j]);
            }
            if (so_far.size() == 14) {
                std::cout << "Day 6 part 2: " << i + 14 << std::endl;
                return;
            }
        }
    }
}
