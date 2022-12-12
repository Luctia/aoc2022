#ifndef AOC2022_STORAGE_H
#define AOC2022_STORAGE_H


#include <map>
#include <stack>
#include <string>
#include <vector>

class Storage {
    std::map<int, std::stack<char>> stacks;
public:
    Storage(const std::vector<std::string>&);
    void rearrange_9000(int, int, int);
    void rearrange_9001(int, int, int);
    std::string get_top_crates();
};


#endif
