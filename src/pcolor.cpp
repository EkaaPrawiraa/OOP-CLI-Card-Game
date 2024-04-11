/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <stdio.h>
#include "color/pcolor.hpp"


std::string colorize(char c, const std::string& color) {
    std::ostringstream oss;
    oss << color << c << NORMAL;
    return oss.str();
}

std::string print_red(char c) {
    return colorize(c, RED);
}

std::string print_green(char c) {
    return colorize(c, GREEN);
}

std::string print_blue(char c) {
    return colorize(c, BLUE);
}