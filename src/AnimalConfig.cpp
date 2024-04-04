#include "Configuration\AnimalConfig.hpp"
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

int AnimalConfig::getid(){
    return id;
}
std::string AnimalConfig::getcode(){
    return kodeHuruf;
}
std::string AnimalConfig::getname(){
    return name;
}
std::string AnimalConfig::gettype(){
    return type;
}
int AnimalConfig::getweighttoharvest(){
    return weightToHarvest;
}

int AnimalConfig::getprice(){
    return price;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE