#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>
#include "../Storage/Storage.hpp"
using namespace std;

class Role
{
private:
    std::string username;
    int gulden;
    float weight;
    Matrix invent;

public:
    Role(string username, float weight, int uang, Matrix invent);
    virtual ~Role();
    virtual void next();
    void cetak_penyimpanan(int baris, int kolom);
    void makan();
    virtual void membeli();
    virtual void menjual();
    virtual int calculate_tax() = 0;
    int getGulden();
    float getWeight();
    void setGulden(int);
    void setWeight(float);
    void setMatrix(Matrix P);
    Matrix getInventory();
};

#endif