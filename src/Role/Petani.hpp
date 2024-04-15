#ifndef PETANI_HPP
#define PETANI_HPP
#include <string>
#include <iostream>
#include <cmath>
#include <regex>
#include "Role.hpp"
#include "../Storage/Storage.hpp"
#include "../item/Building.hpp"
#include "../Store/Store.hpp"
using namespace std;
class Petani : public Role
{
private:
    Matrix<Plant *> Ladang;

public:
    Petani(string username, float weight, int uang, int storrows, int storcols, int ladrows, int ladcols);
     ~Petani();
    
     void membeli(Store&);
     void menjual(Store&);
    void CetakLadang();
    void Tanam();
    void Memanen();
    int calculate_tax();
    void setLadang(int row, char col, Plant *p);
    string getRoleType() override;
    void updateUmurTumbuhan();
    Matrix<Plant*> getLadang() const;
};

#endif