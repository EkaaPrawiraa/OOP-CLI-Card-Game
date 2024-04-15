#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Item.hpp"
#include "Product.hpp"
#include <vector>
#include "../Configuration/AnimalConfig.hpp"
using namespace std;

class Animal : public Item{
public:
    Animal(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location);
    Animal(const Animal&);
    ~Animal();
    Animal(const std::vector<AnimalConfig>& configs, const std::string& name);
    virtual string getclassname();
    string gettype();
    int getweighttoharvest();
    int getberat(); 
    string getlocation();
    bool operator==(const Animal& other) const;
    Animal& operator=(const Animal& other);
    virtual vector<Product*> gethasilpanen();
    pair<char, int> getColumnAndRowIndex(const string& location) const;
    void setberat(int );
protected:
    string type;
    int weightToHarvest;
    int berat;
    string location;
};


#endif
