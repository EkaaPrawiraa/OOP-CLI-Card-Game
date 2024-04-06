#ifndef STORAGE_HPP
#define STORAGE_HPP
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
template<typename T>
class Matrix {
private:
    int rows;
    int cols;
    std::map<char, std::vector<T>> matrix;

public:
    // Constructor with default values for rows and cols
    Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
        // Initialize the matrix with empty strings
        for (char c = 'A'; c < 'A' + cols; ++c) {
            matrix[c] = std::vector<T>(rows);
        }
    }

    // Method to insert element into the matrix
    void set(char key, int index, T value) {
        matrix[key][index-1]=value;
    }

    // Method to display the matrix
    void display(std::string tipe) const {
        std::cout << "     ================[ "<<tipe<<" ]==================" << std::endl << std::endl;
        std::cout << "        ";
        for (char c = 'A'; c < 'A' + this->cols; ++c) { // Qualify cols with 'this->'               
            std::cout << "  " << c << "   ";
        }
        std::cout << std::endl;
        std::cout << "     +-----";
        for (int i = 0; i < this->cols; ++i) { // Qualify cols with 'this->'
            std::cout << "+-----";
        }
        std::cout << "+" << std::endl;

        // Loop for rows
        for (int i = 0; i < this->rows; ++i) { // Qualify rows with 'this->'
            std::cout << "  " << std::setw(2) << i+1 << " |";
            // Loop for columns
            for (char c = 'A'; c < 'A' + this->cols; ++c) { // Qualify cols with 'this->'
                std::cout << std::setw(5) << this->matrix.at(c)[i] << " |"; // Qualify matrix with 'this->'
            }
            std::cout << std::endl << "     +-----";
            for (int i = 0; i < this->cols; ++i) { // Qualify cols with 'this->'
                std::cout << "+-----";
            }
            std::cout << "+" << std::endl;
        }
    }
};
int main(){
    Matrix<int> a(8,8);
    a.set('A', 7, 12);
    a.display("INT");
    return 0;
}

#endif