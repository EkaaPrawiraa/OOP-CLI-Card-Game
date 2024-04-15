#include "BuildingRecipeConfig.hpp"
#include <iostream>

BuildingRecipeConfig::BuildingRecipeConfig(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::pair<std::string, int>> &materials)
    : id(id), kodeHuruf(kodeHuruf), name(name), price(price), materials(materials) {}

void BuildingRecipeConfig::display() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Kode Huruf: " << kodeHuruf << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Materials:" << std::endl;
    for (const auto &material : materials) {
        std::cout << "- " << material.first << ": " << material.second << std::endl;
    }
}

int BuildingRecipeConfig::getid() const {
    return id;
}

std::string BuildingRecipeConfig::getcode() const {
    return kodeHuruf;
}

std::string BuildingRecipeConfig::getname() const {
    return name;
}

int BuildingRecipeConfig::getprice() const {
    return price;
}

std::vector<std::pair<std::string, int>> BuildingRecipeConfig::getmaterials() const {
    return materials;
}
