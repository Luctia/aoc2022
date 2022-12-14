#include "Knot.h"

void Knot::update(int parent_x, int parent_y) {
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
