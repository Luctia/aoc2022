#include <cstdlib>
#include "Knot.h"

void Knot::update(int parent_x, int parent_y) {
    int distance = abs(x - parent_x) + abs(y - parent_y);
    int distance_x = 0;
    int distance_y = 0;

    if (distance >= 4) {
        // move one step in both directions
    } else if (abs(x - parent_x) > 1) {
        if (x - parent_x > 1) {

        }
    } else if (abs(y - parent_y) > 1) {

    }

    if (next != nullptr) {
        next->update(x, y);
    }
}

Knot::Knot() {
    this->next = nullptr;
    x = 0;
    y = 0;
}

void Knot::set_next(Knot *next_knot) {
    this->next = next_knot;
}
