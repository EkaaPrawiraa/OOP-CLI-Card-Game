#ifndef PETANI_HPP
#define PETANI_HPP
#include <string>
#include <iostream>
#include "../PlantAnimal/Plant.hpp"
#include "Role.hpp"
#include "../Storage/Storage.hpp"


using namespace std;
class Petani : public Role{
    private:
        vector<Plant> plant;
        Matrix P;

    public:
        Petani(string username, float weight, int uang, Matrix invent, vector<Plant> p, Matrix P);
        virtual ~Petani();
        virtual void next();
        virtual void membeli();
        virtual void menjual();
        void CetakLadang();
        void Tanam();
        void Memanen();
        virtual int calculate_tax();
        void setMatrix();
};


#endif