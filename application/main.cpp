#include <iostream>
#include <string>

#include "simulator/simulator.h"
int i = 0;
int main(int argc, char *argv[])
{

    int initial_x{0};
    int initial_y{0};
    int inst_x = initial_x;
    int inst_y = initial_y;
    int final_x{15};
    int final_y{15};
    int t = 2;

    // colorize and add text
    // Simulator::setColor(0, 0, 'G');
    // Simulator::setText(0, 0, "A");
    // Simulator::setColor(0, 15, 'G');
    // Simulator::setText(0, 15, "B");
    // Simulator::setColor(15, 15, 'G');
    // Simulator::setText(15, 15, "C");
    // Simulator::setColor(15, 0, 'G');
    // Simulator::setText(15, 0, "D");
    Simulator::setColor(final_x, final_y, 'Y');
    Simulator::setText(final_x, final_y, "G");



    // setting some walls
    // Simulator::setWall(7, 0, 's');
    // Simulator::setWall(8, 0, 's');

        
    // move the robot back and forth
    while (not(inst_x == final_x && inst_y == final_y))
    {
        
         if (Simulator::wallLeft())
        {   
            switch(t%4)
            {
                case 0:
                    Simulator::setWall(inst_x, inst_y, 'e');
                    break;
            }    
            if(Simulator::wallFront())
            {   
                std::cerr << "--- turn right---" << std::endl;
                Simulator::turnRight();
                t++;

                if(Simulator::wallFront())
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

        switch(t%4)
        {

            case 0:
                inst_y--;
                break;

            case 1:
                inst_x--;
                break;
            
            case 2:
                inst_y++;
                break;
            
            case 3:
                inst_x++;
                break;

        }

        std::cerr << "x, y: " << inst_x << " " << inst_y << std::endl;
        Simulator::moveForward();

    }

}
