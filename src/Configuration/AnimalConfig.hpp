#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AnimalConfig
{
public:
    int id;
    std::string kodeHuruf;
    std::string name;
    std::string type;
    int weightToHarvest;
    int price;

    AnimalConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int weightToHarvest, int price);
    void display() const;
};

#endif


// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE