#include <iostream>
#include <fstream>

void day1() {
    std::string line;
    int first = 0;
    int second = 0;
    int third = 0;
    int current = 0;
    std::ifstream Day1Input("../inputs/day1.txt");
    while (getline(Day1Input, line)) {
        if (line == "") {
            if (current > first) {
                third = second;
                second = first;
                first = current;
            } else if (current > second) {
                third = second;
                second = current;
            } else if (current > third) {
                third = current;
            }
            current = 0;
        } else {
            current += std::stoi(line);
        }
    }
    Day1Input.close();
    std::cout << "First: " << first << std::endl;
    std::cout << "Second: " << second << std::endl;
    std::cout << "Third: " << third << std::endl;
    std::cout << "Total: " << first + second + third;
}
