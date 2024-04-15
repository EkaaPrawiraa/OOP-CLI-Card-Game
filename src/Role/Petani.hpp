#ifndef PETANI_HPP
#define PETANI_HPP
#include <string>
#include <iostream>
#include "Role.hpp"
#include "../Storage/Storage.hpp"

using namespace std;
class Petani : public Role
{
private:
    Matrix<Plant *> Ladang;

public:
    Petani(string username, float weight, int uang, int storrows, int storcols, int ladrows, int ladcols);
    virtual ~Petani();
    virtual void next();
    virtual void membeli();
    virtual void menjual();
    void CetakLadang();
    void Tanam();
    void Memanen();
    int calculate_tax();
    void setLadang(int row, char col, Plant *p);
    string getRoleType() override;
    void updateUmurTumbuhan();
};

#endif