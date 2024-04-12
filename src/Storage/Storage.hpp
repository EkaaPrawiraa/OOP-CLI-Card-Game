#ifndef STORAGaE_HPP
#define STORAGaE_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "../color/pcolor.hpp" //Untuk print display
template<typename T>
class Matrix {
private:
    int rows;
    int cols;
    std::map<int, std::map<char, T>> matrix;
    std::string createHeader(std::string type) const;
public:
    // Constructor
    Matrix(int rows, int cols);

    // Function to set value at position (row, col)
    void setValue(int row, char col, T value);
    void setfirstempty(T value);
    // Function to get value at position (row, col)
    T getValue(int row, char col);
    int countElement() const;
    bool isFull();
    void deleteValue(int row, char col);
    virtual void display(std::string tipe);
    int countempty();
    bool isemptyslot(int row, char col);
    bool isempty();
    std::map<int, std::map<char, T>> getmatrix();
};




#endif