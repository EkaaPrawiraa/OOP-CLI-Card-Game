#include "Storage/Storage.hpp"
#include <typeinfo>

using namespace std;
template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {}

// Function to set value at position (row, col)
template <typename T>
void Matrix<T>::setValue(int row, char col, T value)
{
    matrix[row - 1][col] = value;
}

// Function to get value at position (row, col)
template <typename T>
T Matrix<T>::getValue(int row, char col)
{
    return matrix[row - 1][col];
}

template <typename T>
void Matrix<T>::setfirstempty(T value)
{

    for (int row = 0; row < rows; ++row)
    {
        for (char col = 'A'; col < 'A' + cols; ++col)
        {
            if (matrix[row].find(col) == matrix[row].end())
            {
                matrix[row][col] = value;
                return;
            }
        }
    }
}
template <typename T>
int Matrix<T>::countElement() const
{
    int count = 0;
    for (const auto &row : matrix)
    {
        count += row.second.size();
    }
    return count;
}
template <typename T>
bool Matrix<T>::isFull()
{
    return countElement() == rows * cols;
}
template <typename T>
int Matrix<T>::countempty()
{
    return (rows * cols) - countElement();
}

template <typename T>
int Matrix<T>::getSize() 
{
    return rows * cols;
}

template <typename T>
void Matrix<T>::deleteValue(int row, char col)
{
    if (matrix.find(row - 1) != matrix.end() && matrix[row - 1].find(col) != matrix[row - 1].end())
    {
        matrix[row - 1].erase(col);
    }
}

template <typename T>
void Matrix<T>::display(std::string tipe)
{
    // Menghitung lebar kolom untuk penataan rapih
    std::vector<int> column_widths(cols, 0);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix.find(i) != matrix.end() && matrix[i].find('A' + j) != matrix[i].end())
            {
                std::string currentValue;
                std::ostringstream oss;
                oss << matrix[i]['A' + j]->getKode(); // Convert value to string
                currentValue = oss.str();
                int currentWidth = currentValue.size();
                column_widths[j] = std::max(column_widths[j], currentWidth);
            }
            else
            {
                // If the cell is empty, use width of default value "   "
                column_widths[j] = std::max(column_widths[j], 3);
            }
        }
    }

    // Menampilkan matriks dengan penataan rapih

    std::cout << std::endl;
    std::cout << "     ";
    std::cout << createHeader(tipe) << std::endl
              << std::endl;
    std::cout << "      ";
    for (char c = 'A'; c < 'A' + cols; ++c)
    {
        std::cout << "  " << c << std::setw(column_widths[c - 'A'] + 2);
    }
    std::cout << std::endl
              << "     +";
    for (int i = 0; i < cols; ++i)
    {
        std::cout << std::string(column_widths[i] + 2, '-');
        std::cout << "+";
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; ++i)
    {
        std::cout << "  " << std::setw(2) << i + 1 << " |";
        for (int j = 0; j < cols; ++j)
        {
            if (matrix.find(i) != matrix.end() && matrix[i].find('A' + j) != matrix[i].end())
            {
                std::string currentValue;
                std::ostringstream oss;
                oss << matrix[i]['A' + j]->getKode(); // Convert value to string
                currentValue = oss.str();
                std::cout << " " << std::setw(column_widths[j]) << std::left;
                // Check class name using typeid
                std::string classname = matrix[i]['A' + j]->getclassname();
                if (tipe=="Ladang" || tipe=="Peternakan")
                {
                    if (auto animal = dynamic_cast<Animal *>(matrix[i]['A' + j]))
                    {
                        // If class name is Animal, check getWeightToHarvest
                        if (animal->getweighttoharvest() <= 0)
                        {
                            for (char ch : currentValue)
                            {
                                std::cout << print_green(ch);
                            }
                        }
                        else
                        {
                            for (char ch : currentValue)
                            {
                                std::cout << print_red(ch);
                            }
                        }
                    }
                    else if (auto plant = dynamic_cast<Plant *>(matrix[i]['A' + j]))
                    {
                        // If class name is Plant, check getDurationToHarvest
                        if (plant->getdurationtoharvest() <= 0)
                        {
                            for (char ch : currentValue)
                            {
                                std::cout << print_green(ch);
                            }
                        }
                        else
                        {
                            for (char ch : currentValue)
                            {
                                std::cout << print_red(ch);
                            }
                        }
                    }
                    else
                    {
                        std::cout << currentValue;
                    }
                    std::cout << " |";
                }
                else
                {
                    std::cout << currentValue;
                }
                std::cout << " |";
            }
            else
            {
                // If the cell is empty, print "   "
                std::cout << "   " << std::setw(3) << std::left;
                std::cout << "  |";
            }
        }
        std::cout << std::endl
                  << "     +";
        for (int j = 0; j < cols; ++j)
        {
            std::cout << std::string(column_widths[j] + 2, '-');
            std::cout << "+";
        }
        std::cout << std::endl;
    }
}
template <typename T>
bool Matrix<T>::isemptyslot(int row, char col)
{
    return !(matrix.find(row - 1) != matrix.end() && matrix[row - 1].find(col) != matrix[row - 1].end());
}

template <typename T>
std::string Matrix<T>::createHeader(std::string type) const
{
    int width = (6 * cols) + 1;
    int ladangWidth = width - type.length();
    int equalSignsWidth = (ladangWidth - 4) / 2;
    std::string header = std::string(equalSignsWidth, '=') + "[ " + type + " ]" + std::string(equalSignsWidth, '=') + std::string(width % 2, '=');
    return header;
}
template <typename T>
bool Matrix<T>::isempty()
{
    return matrix.empty();
}
template <typename T>
std::map<int, std::map<char, T>> Matrix<T>::getmatrix()
{
    return matrix;
}

template <typename T>
int Matrix<T>::getCols()
{
    return cols;
}

template <typename T>
int Matrix<T>::getRows()
{
    return rows;
}
// int main(){

//     Matrix<Item*> matrix(8,8);
//     Plant* sample = new Plant("ABD", "ABC", "TYPE", -1, 15, 15, "A02");
//     matrix.setValue(3, 'A', sample);
//     matrix.display("Penyimpanan");
//     return 0;
// }
