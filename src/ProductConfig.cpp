#include "Configuration/ProductConfig.hpp"
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

std::string ProductConfig::getcode() const{
    return kodeHuruf;
}
std::string ProductConfig::getname() const{
    return name;
}
std::string ProductConfig::gettype() const{
    return type;
}

std::string ProductConfig::getorigin() const{
    return origin;
}
int ProductConfig::getaddedtoweight() const{
    return addedWeight;
}

int ProductConfig::getprice() const{
    return price;
}