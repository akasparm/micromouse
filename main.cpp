#include <iostream>
#include <string>
#include "simulator/simulator.h"
#include "micromouse/micromouse.h"
#include <cstdlib>


int main(int argc, char *argv[]){
    int direction{10};
    int* p {&direction};
    std::cerr<<*p<<std::endl;
    rwa2group11::Goal a1;
    int* temp = a1.set_goal();
    a1.color_goal();
    rwa2group11::Algorithm b1;


    for(int i=0; i<=15; i++)
    {    
        for(int j=0; j<=15; j++)
        {
            switch(i)
            {
                case 0:
                    Simulator::setWall(i,j,'w');
                    break;
                
                case 15:
                    Simulator::setWall(i,j,'e');
                    break;
            }
            switch(j)
            {
                case 0:
                    Simulator::setWall(i,j,'s');
                    break;

                case 15:
                    Simulator::setWall(i,j,'n');
                    break;                       
            }
        
        }
    }

    if (argc != 2)
    {
        std::cerr << "Usage: ./main l/r \n";
        return 1;
    }

    if (*argv[1] == 'r'){

        b1.right_wall_following(p,temp);
    }
    
    if (*argv[1] == 'l')
    {
    
        b1.left_wall_following(p,temp);
    } 
    
}