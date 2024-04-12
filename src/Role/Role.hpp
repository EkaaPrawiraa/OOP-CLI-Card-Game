#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>
#include "../Storage/Storage.hpp"
#include "../Product/Product.hpp"
using namespace std;

class Role
{
private:
    
protected:
    Matrix invent;
    std::string username;
    int gulden;
    float weight;
    Matrix invent;
    vector<Product> Items;

public:
    Role(string username, float weight, int uang, Matrix invent, vector<Product> Items);
    virtual ~Role();
    virtual void next();
    void cetak_penyimpanan();
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