#include <iostream>
#include <string>
#include "simulator/simulator.h"

int main(int argc, char *argv[])
{

    int initial_x{0};
    int initial_y{0};
    int inst_x = initial_x;
    int inst_y = initial_y;
    int final_x{1};
    int final_y{0};
    int t = 2;

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

    // move the robot back and forth
    while (not(inst_x == final_x && (inst_y) == final_y))
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