#include "Storage\\Storage.hpp"


Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    for (char c = 'A'; c < 'A' + cols; ++c) {
        matrix[c] = std::vector<std::string>(rows, "   ");
    }
}


void Matrix::set(char key, int index, std::string value) {
    if (index >= 1 && index <= rows) { // Ensure the index is within the bounds
        matrix[key][index - 1] = value;
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}


void Matrix::display(std::string tipe) const {
    std::cout << "     ================[ " << tipe << " ]==================" << std::endl << std::endl;
    std::cout << "        ";
    for (char c = 'A'; c < 'A' + cols; ++c) {            
        std::cout << "  " << c << "   ";
    }
    std::cout << std::endl << "     +-----";
    for (int i = 0; i < cols; ++i) {
        std::cout << "+-----";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < rows; ++i) { 
        std::cout << "  " << std::setw(2) << i + 1 << " |";
        for (char c = 'A'; c < 'A' + cols; ++c) {
            std::cout << std::setw(5) << matrix.at(c)[i] << " |"; 
        }
        std::cout << std::endl << "     +-----";
        for (int j = 0; j < cols; ++j) { 
            std::cout << "+-----";
        }
        std::cout << "+" << std::endl;
    }
}

// Method to set the first empty cell with a given value
void Matrix::setfirstempty(std::string value) {
    bool done = false;
    for (char c = 'A'; !done && c < 'A' + cols; ++c) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[c][i] == "   ") {
                matrix[c][i] = value;
                done = true;
                break;
            }
        }
    }

    if (!done) {
        std::cerr << "Error: Storage is full, cannot add new value." << std::endl;
        // Handle the error as needed, maybe throw an exception
    }
}