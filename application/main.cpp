#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include "simulator/simulator.h"
#include "micromouse/micromouse.h"
#include <cstdlib>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Usage: ./main l/r \n";
        return 1;
    }

    int direction{10};
    int *p{&direction};

    rwa2group11::Goal a1;
    int *temp = a1.set_goal();
    a1.color_goal();

    rwa2group11::Algorithm b1;
    b1.set_borders();

    if (*argv[1] == 'r')
    {

        b1.right_wall_following(p, temp);
    }

    if (*argv[1] == 'l')
    {

        b1.left_wall_following(p, temp);
    }

    b1.way_back(p);

    return 0;
}