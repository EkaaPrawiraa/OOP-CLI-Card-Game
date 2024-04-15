#ifndef FARMER_HPP
#define FARMER_HPP

#include "../Store/Store.hpp"
#include "../item/Karnivora.hpp"
#include "../item/Herbivora.hpp"
#include "../item/Omnivora.hpp"
#include "../item/Building.hpp"
#include "../item/Product.hpp"
#include "Role.hpp"
#include "../Storage/Storage.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Farmer : public Role {
private:
    Matrix<Animal*> Peternakan;

public:
    Farmer(string username, int gulden, float weight, int storrow, int storcol, int petrow, int petcol);    
    ~Farmer();
    void cetakPeternakan();
    
    
    void Ternak();
    void Memanen();
    void memberiPangan();


    void menjual(Store& Toko);
    void membeli(Store& Toko);

    int calculate_tax();
    string getRoleType() override;
    void setTernak(int row, char col, Animal *a);
};
// #include "../Farmer.cpp"
#endif // FARMER_HPP