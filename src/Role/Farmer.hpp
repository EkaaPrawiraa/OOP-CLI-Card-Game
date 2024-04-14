#ifndef FARMER_HPP
#define FARMER_HPP

// #include "..//PlantAnimal//Animal.hpp"
// #include "Role.hpp"
// #include "..//Storage//Storage.hpp"
// #include <string>
// #include <vector>
// #include "..//Store//Store.hpp"

#include "../Store/Store.hpp"
#include "../item/Animal.hpp"
#include "Role.hpp"
#include "../Storage/Storage.hpp"
#include <string>
#include <vector>

using namespace std;

class Farmer : public Role
{
private:
    std::vector<Animal> Animals;
    Matrix F;

public:
    Farmer(string username, int gulden, float weight, Matrix invent);
    ~Farmer();
    void setMatrix();
    void cetakPeternakan(int baris, int kolom);
    void ternak(int baris, int kolom);
    virtual void memberiPangan(int baris, int kolom);
    virtual void menjual(Store Toko);
    virtual void membeli(Store Toko);
    int calculate_tax();
    string getRoleType() override;
};

#endif