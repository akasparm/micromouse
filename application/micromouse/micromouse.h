/**
 * @file    micromouse.h
 * @author  Kshitij Karnawat (kshitij@umd.edu)
 * @author  Akashkumar Parmar (akasparm@umd.edu)
 * @author  Sai Teja Gilukara (saitejag@umd.edu)
 * @brief 
 * @version 0.1
 * @date    2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ___MICROMOUSE_H___
#define ___MICROMOUSE_H___

#include <iostream>
#include <array>
#include "../simulator/simulator.h"


/**
 * @brief Namespace under which all classes are defined
 * 
 */
namespace rwa2group11
{
    /**
     * @brief Class that contains methods related to Goal Position
     * 
     */
    class Goal
    {
    protected:
        std::array<int, 2> goal;

    public:
        /**
         * @brief Set the goal
         *
         */
        int *set_goal();

        /**
         * @brief Change the color of the Goal and Set text as 'G'
         *
         */
        void color_goal();
    };

    /**
     * @brief Class that contains methods related to Algorithms to move the Robot
     * 
     */
    class Algorithm
    {
    private:
        std::array<int, 2> curr_loc{0, 0};
        std::vector<std::tuple<int, int>> path;
        std::vector<std::tuple<int, int>> path_f;

    public:
        /**
         * @brief Follow left wall
         * 
         * @param dir pointer to an integer, points to the direction which robot faces
         * @param temp pointer to an array, points to the current coordinate position
         */
        void left_wall_following(int *dir, int *temp);

        /**
         * @brief Follow left wall
         * 
         * @param dir pointer to an integer, points to the direction which robot faces
         * @param temp pointer to an array, points to the current coordinate position
         */
        void right_wall_following(int *dir, int *temp);

        /**
         * @brief Follow left wall
         * 
         * @param dir pointer to an integer, points to the direction which robot faces
         */
        void way_back(int *dir);

        /**
         * @brief Follow left wall
         * 
         * @param dir pointer to an integer, points to the direction which robot faces
         */
        void set_wall(int *dir);

        /**
         * @brief Follow left wall
         * 
         */
        void set_borders();
    };

}

#endif