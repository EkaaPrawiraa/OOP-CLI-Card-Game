#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>
#include <iostream>
#include "../Storage/Storage.hpp"
#include "../item/Item.hpp"
#include "../item/Product.hpp"
#include "../item/Animal.hpp"
// #include "../item/Building.hpp"
#include "../item/Plant.hpp"
using namespace std;

class Role
{
private:
protected:
    std::string username;
    int gulden;
    float weight;
    Matrix<Item *> invent;

public:
    Role(string username, float weight, int uang, int storrows, int storcols);
    virtual ~Role();
    virtual void next();
    void cetak_penyimpanan();
    void makan();
    virtual void membeli();
    virtual void menjual();
    virtual int calculate_tax() = 0;
    std::string getUsername();
    int getGulden();
    float getWeight();
    void setGulden(int);
    void setWeight(float);
    Matrix<Item *> getInventory();
};

#endif