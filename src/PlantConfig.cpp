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

int PlantConfig::getid(){
    return id;
}
std::string PlantConfig::getcode(){
    return kodeHuruf;
}
std::string PlantConfig::getname(){
    return name;
}
std::string PlantConfig::gettype(){
    return type;
}
int PlantConfig::getdurationtoharvest(){
    return durationToHarvest;
}

int PlantConfig::getprice(){
    return price;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE