#ifndef FARMER_HPP
#define FARMER_HPP

#include "..\\PlantAnimal\\Animal.hpp"
#include "Role.hpp"
#include <string>
#include <vector>
using namespace std;

class Farmer : public Role{
private:
    std::vector<Animal> Animals;
public:
    Farmer(string username,int gulden,float weight,inventory invent);
    ~Farmer();
    void cetakPeternakan();
    void ternak();
    virtual void memberiPangan();
    virtual void menjual();
    virtual void membeli();
    int calculate_tax();
};


#endif