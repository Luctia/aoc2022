#include <fstream>
#include <iostream>
#include <vector>


int get_visible(std::vector<std::vector<int>> forest, int row, int col) {
    int tree = forest[row][col];
    int vis_dirs = 4;
    // Check above
    for (int i = 0; i < row; ++i) {
        if (forest[i][col] >= tree ) {
            vis_dirs--;
            break;
        }
    }
    // Check below
    for (int i = row + 1; i < forest.size(); ++i) {
        if (forest[i][col] >= tree ) {
            vis_dirs--;
            break;
        }
    }
    // Check left
    for (int i = 0; i < col; ++i) {
        if (forest[row][i] >= tree) {
            vis_dirs--;
            break;
        }
    }
    // Check right
    for (int i = col + 1; i < forest[row].size(); ++i) {
        if (forest[row][i] >= tree) {
            vis_dirs--;
            break;
        }
    }
    return vis_dirs;
}

int get_dist_to_blocking_tree(std::vector<std::vector<int>> forest, int row, int col) {
    int factors[4] = {0,0,0,0};
    int tree = forest[row][col];
    // Look left
    for (int i = col - 1; i >= 0; --i) {
        if (forest[row][i] >= tree) {
            factors[0] = (col - i);
            break;
        }
        if (i == 0) {
            factors[0] = col;
        }
    }
    // Look right
    for (int i = col + 1; i < forest[row].size(); ++i) {
        if (forest[row][i] >= tree) {
            factors[1] = (i - col);
            break;
        }
        if (i == forest[row].size() - 1) {
            factors[1] = (forest[row].size() - 1 - col);
        }
    }
    // Look up
    for (int i = row - 1; i >= 0; --i) {
        if (forest[i][col] >= tree) {
            factors[2] = row - i;
            break;
        }
        if (i == 0) {
            factors[2] = row;
        }
    }
    // Look down
    for (int i = row + 1; i < forest.size(); ++i) {
        if (forest[i][col] >= tree) {
            factors[3] = (i - row);
            break;
        }
        if (i == forest.size() - 1) {
            factors[3] = (forest.size() - 1 - row);
        }
    }
    return factors[0] * factors[1] * factors[2] * factors[3];
}

int get_highest_scenic_score(std::vector<std::vector<int>> forest) {
    int max_scenic_score = 0;
    // For every tree
    for (int i = 0; i < forest.size(); ++i) {
        for (int j = 0; j < forest[i].size(); ++j) {
            int score = get_dist_to_blocking_tree(forest, i, j);
            if (score > max_scenic_score) {
                max_scenic_score = score;
            }
        }
    }
    return max_scenic_score;
}


void day8part1() {
    std::string line;
    std::ifstream Day8Input("../inputs/day8.txt");
    std::vector<std::vector<int>> forest;
    while (getline(Day8Input, line)) {
        std::vector<int> row;
        for (int i = 0; i < line.size(); ++i) {
            row.push_back(std::stoi(line.substr(i, 1)));
        }
        forest.push_back(row);
    }
    int total = 0;
    for (int i = 0; i < forest.size(); ++i) {
        for (int j = 0; j < forest[i].size(); ++j) {
            if (get_visible(forest, i, j) > 0) {
                total++;
            }
        }
    }
    std::cout << "Day 8 part 1: " << total << std::endl;
}

void day8part2() {
    std::string line;
    std::ifstream Day8Input("../inputs/day8.txt");
    std::vector<std::vector<int>> forest;
    while (getline(Day8Input, line)) {
        std::vector<int> row;
        for (int i = 0; i < line.size(); ++i) {
            row.push_back(std::stoi(line.substr(i, 1)));
        }
        forest.push_back(row);
    }
    std::cout << "Day 8 part 2: " << get_highest_scenic_score(forest) << std::endl;
}