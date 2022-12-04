#include <iostream>
#include <fstream>

void part1() {
    int score = 0;
    std::string line;
    std::ifstream Day2Input("../inputs/day2.txt");
    while (getline(Day2Input, line)) {
        if (line[2] == 'X') {
            score += 1;
            if (line[0] == 'A') {
                score += 3;
            }
            if (line[0] == 'C') {
                score += 6;
            }
        }
        if (line[2] == 'Y') {
            score += 2;
            if (line[0] == 'A') {
                score += 6;
            }
            if (line[0] == 'B') {
                score += 3;
            }
        }
        if (line[2] == 'Z') {
            score += 3;
            if (line[0] == 'B') {
                score += 6;
            }
            if (line[0] == 'C') {
                score += 3;
            }
        }
    }
    std::cout << "Day 2 part 1: " << score << std::endl;
}

void part2() {
    int score = 0;
    std::string line;
    std::ifstream Day2Input("../inputs/day2.txt");
    while (getline(Day2Input, line)) {
        if (line[0] == 'A') {
            if (line[2] == 'X') {
                score += 3;
            }
            if (line[2] == 'Y') {
                score += 4;
            }
            if (line[2] == 'Z') {
                score += 8;
            }
        }
        if (line[0] == 'B') {
            if (line[2] == 'X') {
                score += 1;
            }
            if (line[2] == 'Y') {
                score += 5;
            }
            if (line[2] == 'Z') {
                score += 9;
            }
        }
        if (line[0] == 'C') {
            if (line[2] == 'X') {
                score += 2;
            }
            if (line[2] == 'Y') {
                score += 6;
            }
            if (line[2] == 'Z') {
                score += 7;
            }
        }
    }
    std::cout << "Day 2 part 2: " << score << std::endl;
}
