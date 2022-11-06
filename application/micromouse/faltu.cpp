#include <iostream>
#include <string>
#include "../simulator/simulator.h"
#include <cstdlib>
#include "micromouse.h"

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cerr << "Usage: ./main l/r \n";
        return 1;
    }

    int initial_x{0};
    int initial_y{0};
    int inst_x = initial_x;
    int inst_y = initial_y;
    int final_x;
    int final_y;
    int t = 10;

    
    
    // colorize and add text
    Simulator::setColor(final_x, final_y, 'Y');
    Simulator::setText(final_x, final_y, "G");

    Simulator::setWall(inst_x,inst_y,'s');
    Simulator::setWall(inst_x,inst_y,'w');
    
    if (Simulator::wallFront()){
        Simulator::setWall(inst_x,inst_y,'n');
    }
    
    if (Simulator:: wallRight()){
        Simulator::setWall(inst_x,inst_y,'e');
    }

    if (*argv[1] == 'r'){
        while (!(inst_x == final_x && inst_y == final_y))
        {
            if (Simulator::wallRight())
            {
                if (Simulator::wallFront())
                {
                    std::cerr << "--- turn right---" << std::endl;
                    Simulator::turnLeft();
                    t--;

                    if (Simulator::wallFront())
                    {
                        std::cerr << "--- turn right---" << std::endl;
                        Simulator::turnLeft();
                        t--;
                    }
                }
            }
            else
            {
                std::cerr << "--- turn left ---" << std::endl;
                Simulator::turnRight();
                t++;
            }

            std::cerr << "x, y: " << inst_x << " " << inst_y << std::endl;
            Simulator::moveForward();
            Simulator::setColor(inst_x,inst_y,'g');
            
            rwa_group11::Algorithm ori1; //Give the input
            ori1.set_orientation(10);
        }
    }

    // move the robot back and forth
    if (*argv[1] == 'l'){
        while (!(inst_x == final_x && inst_y == final_y))
        {
            if (Simulator::wallLeft())
            {
                if (Simulator::wallFront())
                {
                    std::cerr << "--- turn right---" << std::endl;
                    Simulator::turnRight();
                    t++;

                    if (Simulator::wallFront())
                    {
                        std::cerr << "--- turn right---" << std::endl;
                        Simulator::turnRight();
                        t++;
                    }
                }
            }
            else
            {
                std::cerr << "--- turn left ---" << std::endl;
                Simulator::turnLeft();
                t--;
            }

            std::cerr << "x, y: " << inst_x << " " << inst_y << std::endl;
            Simulator::moveForward();
            Simulator::setColor(inst_x,inst_y,'g');
            switch (t % 4)
            {
                case 0:
                    inst_y--;
                    if (Simulator::wallFront()){
                        Simulator::setWall(inst_x,inst_y,'s');
                    }
                    if (Simulator::wallLeft()){
                        Simulator::setWall(inst_x,inst_y,'e');
                    }
                    if (Simulator:: wallRight()){
                        Simulator::setWall(inst_x,inst_y,'w');
                    }
                    break;

                case 1:
                    inst_x--;
                    if (Simulator::wallFront()){
                        Simulator::setWall(inst_x,inst_y,'w');
                    }
                    if (Simulator::wallLeft()){
                        Simulator::setWall(inst_x,inst_y,'s');
                    }
                    if (Simulator:: wallRight()){
                        Simulator::setWall(inst_x,inst_y,'n');
                    }
                    break;

                case 2:
                    inst_y++;
                    if (Simulator::wallFront()){
                        Simulator::setWall(inst_x,inst_y,'n');
                    }
                    if (Simulator::wallLeft()){
                        Simulator::setWall(inst_x,inst_y,'w');
                    }
                    if (Simulator:: wallRight()){
                        Simulator::setWall(inst_x,inst_y,'e');
                    }
                    break;

                case 3:
                    inst_x++;
                    if (Simulator::wallFront()){
                        Simulator::setWall(inst_x,inst_y,'e');
                    }
                    if (Simulator::wallLeft()){
                        Simulator::setWall(inst_x,inst_y,'n');
                    }
                    if (Simulator:: wallRight()){
                        Simulator::setWall(inst_x,inst_y,'s');
                    }
                    break;
            }
        }
    }

    return 0;
}

