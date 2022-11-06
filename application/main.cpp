#include <iostream>
#include <string>
#include "simulator/simulator.h"
#include "micromouse/micromouse.h"
#include <cstdlib>

// int main(int argc, char *argv[])
// {

//      //------------------This builds the outer walls-----------------
//        for(int i=0; i<=15; i++)
//        {    
//            for(int j=0; j<=15; j++)
//            {
//                switch(i)
//                {
//                    case 0:
//                        Simulator::setWall(i,j,'w');
//                        break;
                   
//                    case 15:
//                        Simulator::setWall(i,j,'e');
//                        break;
//                }
//                switch(j)
//                {
//                    case 0:
//                        Simulator::setWall(i,j,'s');
//                        break;

//                    case 15:
//                        Simulator::setWall(i,j,'n');
//                        break;                       
//                }
           
//            }
//        }

//     if (argc > 2)
//     {
//         std::cerr << "Usage: ./main l/r \n";
//         return 1;
//     }

//     int initial_x{0};
//     int initial_y{0};
//     int inst_x = initial_x;
//     int inst_y = initial_y;
//     int final_x;
//     int final_y;
//     int t = 2;

//     int flag1;
//     int flag2;

//     srand( (unsigned)time(NULL) );
//     flag1 = rand() % 2;
//     flag2 = rand() % 2;
    
//     if(flag1){
//         final_x = rand() % 15 + 1;
//         if(flag2){
//             final_y = 0;
//             std::cerr << "y - 0";
//         }
//         else{
//             final_y = 15;
//             std::cerr << "y - 15";
//         }
//     }

//     else{
//         final_y = rand() % 15 + 1;
//         if(flag2){
//             final_x = 0;
//             std::cerr << "x - 0";
//         }
//         else{
//             final_x = 15;
//             std::cerr << "x - 15";
//         }
//     }
    
//     // colorize and add text
//     Simulator::setColor(final_x, final_y, 'Y');
//     Simulator::setText(final_x, final_y, "G");

//     Simulator::setWall(inst_x,inst_y,'s');
//     Simulator::setWall(inst_x,inst_y,'w');
    
//     if (Simulator::wallFront()){
//         Simulator::setWall(inst_x,inst_y,'n');
//     }
    
//     if (Simulator:: wallRight()){
//         Simulator::setWall(inst_x,inst_y,'e');
//     }

//     if (*argv[1] == 'r'){
//         while (!(inst_x == final_x && inst_y == final_y))
//         {
//             if (Simulator::wallRight())
//             {
//                 if (Simulator::wallFront())
//                 {
//                     std::cerr << "--- turn right---" << std::endl;
//                     Simulator::turnLeft();
//                     t--;

//                     if (Simulator::wallFront())
//                     {
//                         std::cerr << "--- turn right---" << std::endl;
//                         Simulator::turnLeft();
//                         t--;
//                     }
//                 }
//             }
//             else
//             {
//                 std::cerr << "--- turn left ---" << std::endl;
//                 Simulator::turnRight();
//                 t++;
//             }

//             std::cerr << "x, y: " << inst_x << " " << inst_y << std::endl;
//             Simulator::moveForward();
//             Simulator::setColor(inst_x,inst_y,'g');
//             switch (t % 4)
//             {
//                 case 0:
//                     inst_y--;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'s');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'e');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'w');
//                     }
//                     break;

//                 case 1:
//                     inst_x--;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'w');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'s');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'n');
//                     }
//                     break;

//                 case 2:
//                     inst_y++;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'n');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'w');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'e');
//                     }
//                     break;

//                 case 3:
//                     inst_x++;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'e');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'n');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'s');
//                     }
//                     break;
//             }
//         }
//     }

//     // move the robot back and forth
//     if (*argv[1] == 'l'){
//         while (!(inst_x == final_x && inst_y == final_y))
//         {
//             if (Simulator::wallLeft())
//             {
//                 if (Simulator::wallFront())
//                 {
//                     std::cerr << "--- turn right---" << std::endl;
//                     Simulator::turnRight();
//                     t++;

//                     if (Simulator::wallFront())
//                     {
//                         std::cerr << "--- turn right---" << std::endl;
//                         Simulator::turnRight();
//                         t++;
//                     }
//                 }
//             }
//             else
//             {
//                 std::cerr << "--- turn left ---" << std::endl;
//                 Simulator::turnLeft();
//                 t--;
//             }

//             std::cerr << "x, y: " << inst_x << " " << inst_y << std::endl;
//             Simulator::moveForward();
//             Simulator::setColor(inst_x,inst_y,'g');
//             switch (t % 4)
//             {
//                 case 0:
//                     inst_y--;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'s');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'e');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'w');
//                     }
//                     break;

//                 case 1:
//                     inst_x--;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'w');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'s');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'n');
//                     }
//                     break;

//                 case 2:
//                     inst_y++;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'n');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'w');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'e');
//                     }
//                     break;

//                 case 3:
//                     inst_x++;
//                     if (Simulator::wallFront()){
//                         Simulator::setWall(inst_x,inst_y,'e');
//                     }
//                     if (Simulator::wallLeft()){
//                         Simulator::setWall(inst_x,inst_y,'n');
//                     }
//                     if (Simulator:: wallRight()){
//                         Simulator::setWall(inst_x,inst_y,'s');
//                     }
//                     break;
//             }
//         }
//     }

//     return 0;
// }

int main(){
    int direction{10};
    int* p {&direction};
    std::cerr<<*p<<std::endl;
    



    rwa2group11::Goal a1;
    int* temp = a1.set_goal();
    a1.color_goal();
    rwa2group11::Algorithm b1;
    b1.left_wall_following(p,temp);
}
