#ifndef AOC2022_KNOT_H
#define AOC2022_KNOT_H

#include <set>

class Knot {
    Knot *next;
    int x;
    int y;
    std::set<std::pair<int, int>> visited;
public:
    explicit Knot();
    void update(int parent_x, int parent_y);
    void set_next(Knot *next_knot);
    std::set<std::pair<int, int>> get_visited();
    bool has_next();
    int get_x();
    int get_y();
    void increase_xy(int, int);
    Knot *get_next();
};


#endif
