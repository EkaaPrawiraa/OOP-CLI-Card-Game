#ifndef FARMER_HPP
#define FARMER_HPP

#include "..\\PlantAnimal\\Animal.hpp"
#include "Role.hpp"
#include "..\\Storage\\Storage.hpp"
#include <string>
#include <vector>
using namespace std;

class Farmer : public Role{
private:
    std::vector<Animal> Animals;
    Matrix F;
public:
    Farmer(string username,int gulden,float weight,Matrix invent);
    ~Farmer();
    void setMatrix(Matrix F, int row, int col);
    void cetakPeternakan(int baris, int kolom);
    void ternak(int baris, int kolom);
    virtual void memberiPangan(int baris, int kolom);
    virtual void menjual();
    virtual void membeli();
    int calculate_tax();
};


#endif