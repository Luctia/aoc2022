#include <cstdlib>
#include "Knot.h"

Knot::Knot() {
    this->next = nullptr;
    x = 0;
    y = 0;
}

void Knot::update(int parent_x, int parent_y) {
    int distance_x = abs(x - parent_x);
    int distance_y = abs(y - parent_y);

    if (distance_x == 2 && distance_y == 2) {
        if (x - parent_x < 0) {
            // Parent went right
            this->x++;
        } else {
            // Parent went left
            this->x--;
        }
        if (y - parent_y < 0) {
            // Parent went up
            this->y++;
        } else {
            // Parent went down
            this->y--;
        }
    }

    if (distance_x == 2 && distance_y <= 1) {
        if (x - parent_x < 0) {
            // Parent went right
            this->x++;
        } else {
            // Parent went left
            this->x--;
        }
        if (distance_y == 1) {
            if (y - parent_y < 0) {
                // Parent went up
                this->y++;
            } else {
                // Parent went down
                this->y--;
            }
        }
    }
    if (distance_x <= 1 && distance_y == 2) {
        if (y - parent_y < 0) {
            // Parent went up
            this->y++;
        } else {
            // Parent went down
            this->y--;
        }
        if (distance_x == 1) {
            if (x - parent_x < 0) {
                // Parent went right
                this->x++;
            } else {
                // Parent went left
                this->x--;
            }
        }
    }

    visited.insert({this->x, this->y});

    if (next != nullptr) {
        next->update(this->x, this->y);
    }
}

void Knot::set_next(Knot *next_knot) {
    this->next = next_knot;
}

std::set<std::pair<int, int>> Knot::get_visited() {
    return this->visited;
}

bool Knot::has_next() {
    return next != nullptr;
}

Knot *Knot::get_next() {
    return next;
}

int Knot::get_y() {
    return this->y;
}

int Knot::get_x() {
    return this->x;
}

void Knot::increase_xy(int additional_x, int additional_y) {
    this->x = this->x + additional_x;
    this->y = this->y + additional_y;
}
