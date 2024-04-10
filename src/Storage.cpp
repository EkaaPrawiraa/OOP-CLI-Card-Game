#include "Storage\\Storage.hpp"

int Matrix::count = 0;

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    for (char c = 'A'; c < 'A' + cols; ++c) {
        matrix.push_back(std::vector<std::tuple<std::string, std::string, std::string>>(rows, std::make_tuple("   ", "", "")));
    }
}

std::tuple<std::string, std::string, std::string> Matrix::get(char key, int index) const {
    if (index >= 1 && index <= rows) {
        return matrix[key - 'A'][index - 1];
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
        return std::make_tuple("", "", "");
    }
}

void Matrix::set(char key, int index, std::string value, std::string color, std::string other) {
    if (index >= 1 && index <= rows) {
        matrix[key - 'A'][index - 1] = std::make_tuple(value, color, other);
        count++;
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}

void Matrix::del(char key, int index) {
    if (index >= 1 && index <= rows) {
        // Reset the tuple values to their default values
        std::get<0>(matrix[key - 'A'][index - 1]) = "   ";
        std::get<1>(matrix[key - 'A'][index - 1]) = "";
        std::get<2>(matrix[key - 'A'][index - 1]) = "";
        --count; // Decrement count when an element is erased
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}

void Matrix::setfirstempty(std::string value, std::string color, std::string other) {
    bool done = false;
    for (char c = 'A'; !done && c < 'A' + cols; ++c) {
        for (int i = 0; i < rows; ++i) {
            if (std::get<0>(matrix[c - 'A'][i]) == "   ") {
                std::get<0>(matrix[c - 'A'][i]) = value;
                std::get<1>(matrix[c - 'A'][i]) = color;
                std::get<2>(matrix[c - 'A'][i]) = other;
                done = true;
                break;
            }
        }
    }

    if (!done) {
        std::cerr << "Error: Storage is full, cannot add new value." << std::endl;
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

int Matrix::getSize() const {
    return rows*cols;
}

int Matrix::CountElement() const {
    return count;
}

std::vector<std::pair<std::string, int>> Matrix::getCodeCounts() {
    std::map<std::string, int> codeCounts;
    std::string ready;
    std::string code;
    std::tuple<std::string, std::string, std::string> element;

    for (int i = 1; i < getRows(); ++i) {
        for (char c = 'A'; c < 'A' + getCols(); ++c) {
            element = get(c, i);
            ready = std::get<1>(element);
            code = std::get<0>(element);
            if(ready == "green"){
                codeCounts[code]++;
            }  
        }
    }

    // list yang berisi kode dan jumlah kemunculannya
    std::vector<std::pair<std::string, int>> codeList;
    for (const auto& pair : codeCounts) {
        codeList.push_back(pair);
    }

    return codeList;
}

void Matrix::display(std::string tipe) const {
    // Menghitung lebar kolom untuk penataan rapih
    std::vector<int> column_widths(cols, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::string currentValue = std::get<0>(matrix[j][i]);
            int currentWidth = currentValue.size();
            column_widths[j] = std::max(column_widths[j], currentWidth);
        }
    }

    // Menampilkan matriks dengan penataan rapih
    std::cout << "     ================[ " << tipe << " ]==================" << std::endl << std::endl;
    std::cout << "        ";
    for (char c = 'A'; c < 'A' + cols; ++c) {
        std::cout << "  " << c << std::setw(column_widths[c - 'A'] + 1);
    }
    std::cout << std::endl << "     +";
    for (int i = 0; i < cols; ++i) {
        std::cout << std::string(column_widths[i] + 3, '-');
        std::cout << "+";
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; ++i) {
        std::cout << "  " << std::setw(2) << i + 1 << " |";
        for (int j = 0; j < cols; ++j) {
            std::string currentValue = std::get<0>(matrix[j][i]);
            std::string currentColor = std::get<1>(matrix[j][i]);
            std::cout << " " << std::setw(column_widths[j]) << std::left;
            if (currentColor == "green") {
                for (char ch : currentValue) {
                    print_green(ch);
                }
            } else if (currentColor == "red") {
                for (char ch : currentValue) {
                    print_red(ch);
                }
            } else {
                std::cout << currentValue;
            }
            std::cout << " |";
        }
        std::cout << std::endl << "     +";
        for (int j = 0; j < cols; ++j) {
            std::cout << std::string(column_widths[j] + 3, '-');
            std::cout << "+";
        }
        std::cout << std::endl;
    }
}



