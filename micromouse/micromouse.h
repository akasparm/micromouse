#ifndef ___MICROMOUSE_H___
#define ___MICROMOUSE_H___

#include <iostream>
#include <array>
#include "../simulator/simulator.h"

#pragma once


namespace rwa2group11{
    class Goal{
        protected:
            std::array<int,2> goal;
            
        public:
            /**
             * @brief Set the goal
             * 
             */
            int* set_goal();

            /**
             * @brief Change the color of the Goal and Set text as 'G'
             * 
             * @param x 
             * @param y 
             */
            void color_goal();
    };
    


    class Algorithm{
        private:
            std::array<int,2> curr_loc{0,0};
            

        public:
            void left_wall_following(int* dir,int* temp);
            void right_wall_following(int* dir, int* temp);
            void way_back();
            void set_wall(int* dir);

    };

}

#endif