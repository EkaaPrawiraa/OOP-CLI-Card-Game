#include "item/Building.hpp"

// Buiilding class implementation
Material::Material(const std::string &name, int quantity)
    : name(name), quantity(quantity) {}

Building::Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials)
    : Item(kodeHuruf, name, price), materials(materials) {}

Building::Building(const Building& other)
    : Item(other), materials(other.materials){}

Building::~Building() {}

std::vector<Material> Building::getmaterials(){
    return materials;
}
string Building::getclassname(){
    return "Building";
}