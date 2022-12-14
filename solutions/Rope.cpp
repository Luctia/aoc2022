#include "Rope.h"

Rope::Rope(int length) {
    if (length == 0) {
        return;
    }
    Knot *first_knot = new Knot();
    Knot *latest = first_knot;
    for (int i = 0; i < length - 1; ++i) {
        Knot *next_knot = new Knot();
        latest->set_next(next_knot);
        latest = next_knot;
    }
}
