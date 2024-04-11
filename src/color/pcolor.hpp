/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

#include <iostream>
#include <string>
#include <sstream>

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"

std::string colorize(char c, const std::string& color);

std::string print_red(char c);

std::string print_green(char c);

std::string print_blue(char c);