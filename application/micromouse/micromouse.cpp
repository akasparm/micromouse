#include <iostream>
#include <array>
#include <memory>
#include "micromouse.h"

int* rwa2group11::Goal::set_goal(){

    srand((unsigned)time(NULL));

    int flag1 = rand() % 2;
    int flag2 = rand() % 2;
    
    if(flag1){
        goal[0] = rand() % 16;
        if(flag2){
            goal[1] = 0;
        }
        else{
            goal[1] = 15;
        }
    }

    else{
        goal[1] = rand() % 16;
        if(flag2){
            goal[0] = 0;
        }
        else{
            goal[0] = 15;
        }
    }
    return goal.data();
}

void rwa2group11::Goal::color_goal(){
    
    // colorize and add text
    Simulator::setColor(goal[0], goal[1], 'Y');
    Simulator::setText(goal[0], goal[1], "G");
}

void rwa2group11::Algorithm::left_wall_following(int* dir, int* temp){
    // std::cerr<<curr_loc[0]<<std::endl;
    // int* temp = rwa2group11::Goal::set_goal();
    // temp = goal.data()
    // std::cerr<<*temp<<std::endl;
    
    int goal_x = *temp;
    int goal_y = *(temp+1);
    std::cerr<<*dir<<std::endl;
    
    while (!(curr_loc[0] == goal_x && curr_loc[1] == goal_y)){
    
        if (Simulator::wallLeft()){
    
            if (Simulator::wallFront()){
    
                std::cerr << "--- turn right---" << std::endl;
                Simulator::turnRight();
                *dir = *dir + 1;
                std::cerr<<*dir<<std::endl;
                

                if (Simulator::wallFront()){
    
                    std::cerr << "--- turn right---" << std::endl;
                    Simulator::turnRight();
                    *dir = *dir + 1;
                }
            }
        }
        else{
    
            std::cerr << "--- turn left ---" << std::endl;
            Simulator::turnLeft();
            *dir = *dir - 1;
        }

        std::cerr << "x, y: " << curr_loc[0] << " " << curr_loc[1] << std::endl;
        Simulator::moveForward();
        Simulator::setColor(curr_loc[0],curr_loc[1],'g');
        Algorithm::set_wall(dir);
    }
}


// void rwa2group11::Algorithm::right_wall_following(){

//     while (!(curr_loc[0] == goal[0] && curr_loc[1] == goal[1]))
//     {
//         if (Simulator::wallRight())
//         {
//             if (Simulator::wallFront())
//             {
//                 std::cerr << "--- turn right---" << std::endl;
//                 Simulator::turnLeft();
//                 direction--;

//                 if (Simulator::wallFront())
//                 {
//                     std::cerr << "--- turn right---" << std::endl;
//                     Simulator::turnLeft();
//                     direction--;
//                 }
//             }
//         }
//         else
//         {
//             std::cerr << "--- turn left ---" << std::endl;
//             Simulator::turnRight();
//             direction++;
//         }

//         std::cerr << "x, y: " << curr_loc[0] << " " << curr_loc[1] << std::endl;
//         Simulator::moveForward();
//         Simulator::setColor(curr_loc[0],curr_loc[1],'g');
//         Algorithm::set_wall(direction);
//     }
// }


void rwa2group11::Algorithm::set_wall(int* dir)       //  Give input of Algorithm::direction changed in lwa/rwa function.
{
//      Don't forget to replace curr_loc[0],[1] with pointvalues.

    switch (*dir % 4)
    {
        case 0:
            curr_loc[1]--;
            if (Simulator::wallFront()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'s');
            }
            if (Simulator::wallLeft()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'e');
            }
            if (Simulator:: wallRight()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'w');
            }
            break;

        case 1:
            curr_loc[0]--;
            if (Simulator::wallFront()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'w');
            }
            if (Simulator::wallLeft()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'s');
            }
            if (Simulator:: wallRight()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'n');
            }
            break;

        case 2:
            curr_loc[1]++;
            if (Simulator::wallFront()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'n');
            }
            if (Simulator::wallLeft()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'w');
            }
            if (Simulator:: wallRight()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'e');
            }
            break;

        case 3:
            curr_loc[0]++;
            if (Simulator::wallFront()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'e');
            }
            if (Simulator::wallLeft()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'n');
            }
            if (Simulator:: wallRight()){
                Simulator::setWall(curr_loc[0],curr_loc[1],'s');
            }
            break;
    }

}
