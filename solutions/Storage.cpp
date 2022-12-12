#include <iostream>
#include "Storage.h"

Storage::Storage(const std::vector<std::string>& lines) {
    for (std::string line:lines) {
        int index = 0;
        while (index < line.size()) {
            if (line[index] == '[') {
                stacks[index / 4 + 1].push(line[index + 1]);
            }
            index += 4;
        }
    }
    for (auto & stack : stacks) {
        std::stack<char> temp;
        while (!stack.second.empty()) {
            temp.push(stack.second.top());
            stack.second.pop();
        }
        stacks[stack.first] = temp;
    }
};

void Storage::rearrange_9000(int from_stack, int to_stack, int amount) {
    for (int i = 0; i < amount; ++i) {
        stacks[to_stack].push(stacks[from_stack].top());
        stacks[from_stack].pop();
    }
}

void Storage::rearrange_9001(int from_stack, int to_stack, int amount) {
    std::vector<char> taken;
    for (int i = 0; i < amount; ++i) {
        taken.push_back(stacks[from_stack].top());
        stacks[from_stack].pop();
    }
    for (int i = amount - 1; i >= 0; --i) {
        stacks[to_stack].push(taken.at(i));
    }
}

std::string Storage::get_top_crates() {
    std::string result;
    for (auto stack : stacks) {
        result += stacks[stack.first].top();
    }
    return result;
}
