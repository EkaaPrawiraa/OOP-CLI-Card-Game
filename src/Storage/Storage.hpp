#ifndef STORAGE_HPP
#define STORAGE_HPP
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
// template<typename T>
class Matrix {
private:
    int rows;
    int cols;
    std::map<char, std::vector<std::string>> matrix;

public:

    Matrix(int rows = 0, int cols = 0);


    void set(char key, int index, std::string value);


    void display(std::string tipe) const;
    void setfirstempty(std::string value);
};

#endif