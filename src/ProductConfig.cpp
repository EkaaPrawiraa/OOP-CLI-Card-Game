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

std::string ProductConfig::getcode(){
    return kodeHuruf;
}
std::string ProductConfig::getname(){
    return name;
}
std::string ProductConfig::gettype(){
    return type;
}

std::string ProductConfig::getorigin(){
    return origin;
}
int ProductConfig::getaddedtoweight(){
    return addedWeight;
}

int ProductConfig::getprice(){
    return price;
}