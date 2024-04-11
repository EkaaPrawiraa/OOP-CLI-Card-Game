/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <stdio.h>
#include "pcolor.hpp"

int main()
{
    char a = 'T';
    char b = 'E';
    char c = 'K';

    print_red(a);
    print_red(b);
    print_red(c);

    printf("\n");
    return 0;
}

