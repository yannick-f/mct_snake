#ifndef FOOD_H
#define FOOD_H

#include "Coordinate.h"

class Food {
private:
    Coordinate pos = get_position();
    int x_max = 32;
    int y_max = 32;

public:

    void generate_new_food();

    Coordinate get_position();
};

#endif // FOOD_H
