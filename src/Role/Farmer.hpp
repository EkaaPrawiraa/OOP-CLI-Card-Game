#ifndef FARMER_HPP
#define FARMER_HPP

#include "../Store/Store.hpp"
#include "../item/Animal.hpp"
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
    void cetakPeternakan(int baris, int kolom);
    void ternak(int baris, int kolom);
    void memberiPangan(int baris, int kolom);

    template<typename T>
    void menjual(Store& Toko);

    template<typename T>
    void membeli(Store& Toko);

    void membeli(Store& Toko);
    void menjual(Store& Toko);

    int calculate_tax();
    string getRoleType() override;
};
#include "../Farmer.cpp"
#endif // FARMER_HPP
