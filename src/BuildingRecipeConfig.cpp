#include "Configuration/BuildingRecipeConfig.hpp"
#include <iostream>

Material::Material(const std::string &name, int quantity)
    : name(name), quantity(quantity) {}

BuildingRecipeConfig::BuildingRecipeConfig(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials)
    : id(id), kodeHuruf(kodeHuruf), name(name), price(price), materials(materials) {}

void BuildingRecipeConfig::display() const
{
    std::cout << "ID: " << id << ", "
              << "Kode Huruf: " << kodeHuruf << ", "
              << "Name: " << name << ", "
              << "Price: " << price << std::endl;

    std::cout << "Materials:" << std::endl;
    for (const auto &material : materials)
    {
        std::cout << "- " << material.name << ": " << material.quantity << std::endl;
    }
}
int BuildingRecipeConfig::getid(){
    return id;
}
std::string BuildingRecipeConfig::getcode(){
    return kodeHuruf;
}
std::string BuildingRecipeConfig::getname(){
    return name;
}
int BuildingRecipeConfig::getprice(){
    return price;
}
std::vector<Material> BuildingRecipeConfig::getmaterials(){
    return materials;
}
