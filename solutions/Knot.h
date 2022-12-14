#ifndef AOC2022_KNOT_H
#define AOC2022_KNOT_H


class Knot {
    Knot *next;
    int x;
    int y;
public:
    explicit Knot();
    void update(int parent_x, int parent_y);
    void set_next(Knot *next_knot);
};


#endif
