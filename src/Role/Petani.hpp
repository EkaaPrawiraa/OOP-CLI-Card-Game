#ifndef PETANI_HPP
#define PETANI_HPP
#include <string>
#include <iostream>
#include "PlantAnimal\\Plant.hpp"
#include "Role.hpp"
#include "..\\Storage\\Storage.hpp"

using namespace std;
class Petani : public Role{
    private:
        vector<Plant> plant;
        Matrix L;

    public:
        Petani(string username, float weight, int uang, Matrix invent);
        virtual ~Petani();
        virtual void next();
        virtual void membeli();
        virtual void menjual();
        void CetakLadang(int row, int col);
        void Tanam();
        void Memanen();
        virtual int calculate_tax()=0;
        void setMatrix(Matrix P, int row, int col);
};


#endif