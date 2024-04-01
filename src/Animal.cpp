#include "Animal\Animal.hpp"
#include <iostream>

Animal::Animal(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int weightToHarvest, int price)
    : id(id), kodeHuruf(kodeHuruf), name(name), type(type), weightToHarvest(weightToHarvest), price(price) {}

void Animal::display() const
{
    std::cout << "ID: " << id << ", "
              << "Kode Huruf: " << kodeHuruf << ", "
              << "Name: " << name << ", "
              << "Type: " << type << ", "
              << "Weight to Harvest: " << weightToHarvest << ", "
              << "Price: " << price << std::endl;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE