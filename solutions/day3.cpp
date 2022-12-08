#include <iostream>
#include <fstream>
#include <algorithm>

int getPriority(char letter) {
    int val = (int)letter;
    if (val > 90) {
        return val - 96;
    } else {
        return val - 38;
    }
}

std::string get_intersection(std::string string1, std::string string2) {
    std::string intersection;
    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());
    std::set_intersection(string1.begin(), string1.end(), string2.begin(), string2.end(), std::back_inserter(intersection));
    return intersection;
}

void day3part1() {
    std::string line;
    int sum_of_priorities = 0;
    std::ifstream Day3Input("../inputs/day3.txt");
    while (getline(Day3Input, line)) {
        int length = line.size();
        std::string compartment1 = line.substr(0, length / 2);
        std::string compartment2 = line.substr(length / 2);
        sum_of_priorities += getPriority(get_intersection(compartment1, compartment2)[0]);
    }
    std::cout << "Day 3 part 1: " << sum_of_priorities << std::endl;
}

void day3part2() {
    std::string line1;
    std::string line2;
    std::string line3;
    int sum_of_priorities = 0;
    std::ifstream Day3Input("../inputs/day3.txt");
    while (getline(Day3Input, line1)) {
        getline(Day3Input, line2);
        getline(Day3Input, line3);
        sum_of_priorities += getPriority(get_intersection(line1, get_intersection(line2, line3))[0]);
    }
    std::cout << "Day 3 part 2: " << sum_of_priorities << std::endl;
}
