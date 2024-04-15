#include "Configuration/PlantConfig.hpp"
#include <iostream>

PlantConfig::PlantConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int durationToHarvest, int price)
: id(id), kodeHuruf(kodeHuruf), name(name), type(type), durationToHarvest(durationToHarvest), price(price) {}

void PlantConfig::display() const
{
std::cout << "ID: " << id << ", "
            << "Kode Huruf: " << kodeHuruf << ", "
            << "Name: " << name << ", "
            << "Type: " << type << ", "
            << "Duration to Harvest: " << durationToHarvest << ", "
            << "Price: " << price << std::endl;
}

int PlantConfig::getid() const{
    return id;
}
std::string PlantConfig::getcode() const{
    return kodeHuruf;
}
std::string PlantConfig::getname() const{
    return name;
}
std::string PlantConfig::gettype() const{
    return type;
}
int PlantConfig::getdurationtoharvest() const{
    return durationToHarvest;
}

int PlantConfig::getprice() const{
    return price;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE