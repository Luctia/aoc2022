#include "Rope.h"

Rope::Rope(int length) {
    if (length == 0) {
        return;
    }
    this->first = new Knot();
    Knot *latest = this->first;
    for (int i = 0; i < length - 1; ++i) {
        Knot *next_knot = new Knot();
        latest->set_next(next_knot);
        latest = next_knot;
    }
}

Knot *Rope::get_last() {
    Knot *val = this->first;
    while (val->has_next()) {
        val = val->get_next();
    }
    return val;
}

void Rope::move_head(char dir, int steps) {
    if (dir == 'R') {
        for (int i = 0; i < steps; ++i) {
            this->first->increase_xy(1, 0);
            this->first->get_next()->update(this->first->get_x(), this->first->get_y());
        }
    }
    if (dir == 'U') {
        for (int i = 0; i < steps; ++i) {
            this->first->increase_xy(0, 1);
            this->first->get_next()->update(this->first->get_x(), this->first->get_y());
        }
    }
    if (dir == 'L') {
        for (int i = 0; i < steps; ++i) {
            this->first->increase_xy(-1, 0);
            this->first->get_next()->update(this->first->get_x(), this->first->get_y());
        }
    }
    if (dir == 'D') {
        for (int i = 0; i < steps; ++i) {
            this->first->increase_xy(0, -1);
            this->first->get_next()->update(this->first->get_x(), this->first->get_y());
        }
    }
}
