#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <iostream>
#include "PlantAnimal/Plant.hpp"
#include "Role.hpp"
using namespace std;
class User : public Role{
    private:
        vector<Plant> plant;

    public:
        User(string username, float weight, int uang);
        virtual ~User();
        virtual void next();
        virtual void membeli();
        virtual void menjual();
        void CetakLadang();
        void Tanam();
        void Memanen();
        virtual int calculate_tax()=0;
};


#endif