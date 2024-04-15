#include "Configuration/AnimalConfig.hpp"
#include <iostream>

AnimalConfig::AnimalConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int weightToHarvest, int price)
    : id(id), kodeHuruf(kodeHuruf), name(name), type(type), weightToHarvest(weightToHarvest), price(price) {}

void AnimalConfig::display() const
{
    std::cout << "ID: " << id << ", "
              << "Kode Huruf: " << kodeHuruf << ", "
              << "Name: " << name << ", "
              << "Type: " << type << ", "
              << "Weight to Harvest: " << weightToHarvest << ", "
              << "Price: " << price << std::endl;
}

int AnimalConfig::getid() const{
    return id;
}
std::string AnimalConfig::getcode() const{
    return kodeHuruf;
}
std::string AnimalConfig::getname() const{
    return name;
}
std::string AnimalConfig::gettype() const{
    return type;
}
int AnimalConfig::getweighttoharvest() const{
    return weightToHarvest;
}

int AnimalConfig::getprice() const{
    return price;
}
AnimalConfig& AnimalConfig::operator=(const AnimalConfig& other)
{
    if (this != &other) // prevent self-assignment
    {
        id = other.id;
        kodeHuruf = other.kodeHuruf;
        name = other.name;
        type = other.type;
        weightToHarvest = other.weightToHarvest;
        price = other.price;
    }
    return *this;
}

// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE