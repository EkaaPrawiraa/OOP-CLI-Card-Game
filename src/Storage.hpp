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

    Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {

        for (char c = 'A'; c < 'A' + cols; ++c) {
            matrix[c] = std::vector<std::string>(rows, "   ");
        }
    }


    void set(char key, int index, std::string value) {
        matrix[key][index-1]=value;
    }


    void display(std::string tipe) const {
        std::cout << "     ================[ "<<tipe<<" ]==================" << std::endl << std::endl;
        std::cout << "        ";
        for (char c = 'A'; c < 'A' + this->cols; ++c) {            
            std::cout << "  " << c << "   ";
        }
        std::cout << std::endl;
        std::cout << "     +-----";
        for (int i = 0; i < this->cols; ++i) {
            std::cout << "+-----";
        }
        std::cout << "+" << std::endl;


        for (int i = 0; i < this->rows; ++i) { 
            std::cout << "  " << std::setw(2) << i+1 << " |";

            for (char c = 'A'; c < 'A' + this->cols; ++c) {
                std::cout << std::setw(5) << this->matrix.at(c)[i] << " |"; 
            }
            std::cout << std::endl << "     +-----";
            for (int i = 0; i < this->cols; ++i) { 
                std::cout << "+-----";
            }
            std::cout << "+" << std::endl;
        }
    }
    void setfirstempty(string value){
        bool done=false;
        for (char c = 'A'; c < 'A' + cols; ++c) {
            for (std::string& val : matrix[c]){
                if (val=="   "){
                    val=value;
                    done=true;
                    break;
                }
            }
            if (done){
                break;
            }
        }
        if (!done){
            // THROW EXCEPTION STORAGE PENUH
        }
    }
};

#endif