#include "item/Building.hpp"

Building::Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::pair<std::string, int> >& materials)
    : Item(kodeHuruf, name, price), materials(materials) {}

Building::Building(const Building& other)
    : Item(other), materials(other.materials) {}

Building::~Building() {}

vector< pair<string, int> > Building::getmaterials() const {
    return materials;
}

std::string Building::getclassname() {
    return "Building";
}

bool Building::operator==(const Building& other) const {
    return (this->name == other.name) &&
           (this->kodeHuruf == other.kodeHuruf) &&
           (this->price == other.price) &&
           (this->materials == other.materials); // perbandingan material
}

Building& Building::operator=(const Building& other) {
    if (this != &other) {
        this->name = other.name;
        this->kodeHuruf = other.kodeHuruf;
        this->price = other.price;
        this->materials = other.materials; // penugasan material
    }
    return *this;
}

