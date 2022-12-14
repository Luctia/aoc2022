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
