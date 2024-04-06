#include "PlantAnimal/Plant.hpp"

// Plant class implementation
Plant::Plant(const string &kodeHuruf, const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location)
    : kodeHuruf(kodeHuruf), name(name), type(type), durationToHarvest(durationToHarvest), price(price), umur(umur), location(location) {}

Plant::Plant(const Plant& other)
    : kodeHuruf(other.kodeHuruf), name(other.name), type(other.type), durationToHarvest(other.durationToHarvest), price(other.price), umur(other.umur), location(other.location) {}

Plant::~Plant() {}

void Plant::display() const {
    // Implement display function as needed
}

string Plant::getname() const {
    return name;
}

string Plant::gettype() {
    return type;
}

int Plant::getdurationtoharvest() {
    return durationToHarvest;
}

int Plant::getprice() {
    return price;
}

string Plant::getlocation() const {
    return location;
}

int Plant::getumur() const {
    return umur;
}
string Plant::getKode() const
{
    return kodeHuruf;
}

// MaterialPlant class implementation
MaterialPlant::MaterialPlant(const string &kodeHuruf, const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location)
    : Plant(kodeHuruf, name, type, durationToHarvest, price, umur, location), hasilpanen(1) {}

MaterialPlant::MaterialPlant(const Plant& other)
    : Plant(other), hasilpanen(1) {}

MaterialPlant::~MaterialPlant() {}

int MaterialPlant::gethasilpanen() {
    // if (name == "Teak_Tree") {
    //     return 1;
    // } else if (name == "Sandalwood_Tree") {
    //     return 1;
    // } else if (name == "Aloe_Tree") {
    //     return 1;
    // } else if (name == "Ironwood_Tree") {
    //     return 1;
    // }
    return hasilpanen;
}

// FruitPlant class implementation
FruitPlant::FruitPlant(const string &kodeHuruf, const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location)
    : Plant(kodeHuruf, name, type, durationToHarvest, price, umur, location), hasilpanen(1) {}

FruitPlant::FruitPlant(const Plant& other)
    : Plant(other), hasilpanen(1) {}

FruitPlant::~FruitPlant() {}

int FruitPlant::gethasilpanen() {
    // if (name == "Teak_Tree") {
    //     return 1;
    // } else if (name == "Sandalwood_Tree") {
    //     return 1;
    // } else if (name == "Aloe_Tree") {
    //     return 1;
    // } else if (name == "Ironwood_Tree") {
    //     return 1;
    // }
    return hasilpanen;
}
