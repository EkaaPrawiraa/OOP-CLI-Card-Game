#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>
#include "../Storage/Storage.hpp"
#include "Item/Item.hpp"
#include "Item/Product.hpp"
#include "Item/Animal.hpp"
#include "Item/Building.hpp"
#include "Item/Plant.hpp"
using namespace std;

class Role
{
private:
    
protected:
    std::string username;
    int gulden;
    float weight;
    Matrix<Item*> invent;

public:
    Role(string username, float weight, int uang, int storrows, int storcols);
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
    Matrix<Item*> getInventory();
    
};

#endif