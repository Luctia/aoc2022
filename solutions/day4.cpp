#include <iostream>
#include <fstream>

void day4part1() {
    std::string line;
    int containments = 0;
    std::ifstream Day4Input("../inputs/day4.txt");
    while (getline(Day4Input, line)) {
        int comma_index = line.find(',');
        std::string elf1 = line.substr(0, comma_index);
        int dash_index = elf1.find('-');
        int elf1start = std::stoi(elf1.substr(0, dash_index));
        int elf1end = std::stoi(elf1.substr(dash_index + 1));
        std::string elf2 = line.substr(comma_index + 1);
        dash_index = elf2.find('-');
        int elf2start = std::stoi(elf2.substr(0, dash_index));
        int elf2end = std::stoi(elf2.substr(dash_index + 1));
        if ((elf1start >= elf2start && elf1end <= elf2end) || (elf2start >= elf1start && elf2end <= elf1end)) {
            containments++;
        }
    }
    std::cout << "Day 4 part 1: " << containments << std::endl;
}

void day4part2() {
    std::string line;
    int overlaps = 0;
    std::ifstream Day4Input("../inputs/day4.txt");
    while (getline(Day4Input, line)) {
        int comma_index = line.find(',');
        std::string elf1 = line.substr(0, comma_index);
        int dash_index = elf1.find('-');
        int elf1start = std::stoi(elf1.substr(0, dash_index));
        int elf1end = std::stoi(elf1.substr(dash_index + 1));
        std::string elf2 = line.substr(comma_index + 1);
        dash_index = elf2.find('-');
        int elf2start = std::stoi(elf2.substr(0, dash_index));
        int elf2end = std::stoi(elf2.substr(dash_index + 1));
        if ((elf1start <= elf2end && elf1end >= elf2start) || (elf2start <= elf1end && elf2end >= elf1start)) {
            overlaps++;
        }
    }
    std::cout << "Day 4 part 2: " << overlaps << std::endl;
}
