#include "Configuration\ProductConfig.hpp"
#include <iostream>

ProductConfig::ProductConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, const std::string &origin, int addedWeight, int price)
    : id(id), kodeHuruf(kodeHuruf), name(name), type(type), origin(origin), addedWeight(addedWeight), price(price) {}

void ProductConfig::display() const
{
    std::cout << "ID: " << id << ", "
              << "Kode Huruf: " << kodeHuruf << ", "
              << "Name: " << name << ", "
              << "Type: " << type << ", "
              << "Origin: " << origin << ", "
              << "Added Weight: " << addedWeight << ", "
              << "Price: " << price << std::endl;
}
