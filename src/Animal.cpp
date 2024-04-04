#include "PlantAnimal/Animal.hpp"

// Animal class implementation
Animal::Animal(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
    : kodeHuruf(kodeHuruf), name(name), type(type), weightToHarvest(weightToHarvest), price(price), berat(berat), location(location) {}

Animal::Animal(const Animal& other)
    : kodeHuruf(other.kodeHuruf), name(other.name), type(other.type), weightToHarvest(other.weightToHarvest), price(other.price), berat(other.berat), location(other.location) {}

Animal::~Animal() {}


string Animal::getname() const {
    return name;
}

string Animal::gettype() {
    return type;
}

int Animal::getweighttoharvest() {
    return weightToHarvest;
}

int Animal::getprice() {
    return price;
}

int Animal::getberat() {
    return berat;
}

string Animal::getlocation() {
    return location;
}

// Herbivora class implementation
Herbivora::Herbivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
    : Animal(kodeHuruf, name, type, weightToHarvest, price, berat, location), hasilpanen(1) {}

Herbivora::Herbivora(const Animal& other)
    : Animal(other), hasilpanen(1) {}

Herbivora::~Herbivora() {}

int Herbivora::gethasilpanen() {
    return hasilpanen;
}

// Karnivora class implementation
Karnivora::Karnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location) : Animal(kodeHuruf, name, type, weightToHarvest, price, berat, location), hasilpanen(1) {}

Karnivora::Karnivora(const Animal& other)
    : Animal(other), hasilpanen(1) {}

Karnivora::~Karnivora() {}

int Karnivora::gethasilpanen() {
    return hasilpanen;
}

// Omnivora class implementation
Omnivora::Omnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
    : Animal(kodeHuruf, name, type, weightToHarvest, price, berat, location), hasilpanen(2) {}

Omnivora::Omnivora(const Animal& other)
    : Animal(other), hasilpanen(1) {}

Omnivora::~Omnivora() {}

int Omnivora::gethasilpanen() {
    return hasilpanen;
}
