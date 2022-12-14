#ifndef AOC2022_ROPE_H
#define AOC2022_ROPE_H


#include "Knot.h"

class Rope {
    Knot *first;
public:
    explicit Rope(int length);
    Knot *get_last();
    void move_head(char, int);
};


#endif
