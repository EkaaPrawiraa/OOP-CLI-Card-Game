#include "Building/BuildingRecipe.hpp"
#include <iostream>

Material::Material(const std::string &name, int quantity)
    : name(name), quantity(quantity) {}

BuildingRecipe::BuildingRecipe(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials)
    : id(id), kodeHuruf(kodeHuruf), name(name), price(price), materials(materials) {}

void BuildingRecipe::display() const
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
