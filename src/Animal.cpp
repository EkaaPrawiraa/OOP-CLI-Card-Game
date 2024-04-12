#include "item/Animal.hpp"

// Animal class implementation
Animal::Animal(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
    : Item(kodeHuruf, name, price), type(type), weightToHarvest(weightToHarvest), berat(berat), location(location) {}

Animal::Animal(const Animal& other)
    : Item(other), type(other.type), weightToHarvest(other.weightToHarvest), berat(other.berat), location(other.location) {}

Animal::~Animal() {}

pair<char, int> Animal::getColumnAndRowIndex(const string& location) const{
    char column = location[0]; 
    int row = stoi(location.substr(1)); 
    return make_pair(column, row);
}

string Animal::gettype() {
    return type;
}

int Animal::getweighttoharvest() {
    return weightToHarvest;
}

int Animal::getprice() const {
    return price;
}

int Animal::getberat() {
    return berat;
}

string Animal::getlocation() {
    return location;
}

// Herbivora class implementation
// Herbivora::Herbivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
//     : Animal(kodeHuruf, name, type, weightToHarvest, price, berat, location), hasilpanen(1) {}

// Herbivora::Herbivora(const Animal& other)
//     : Animal(other), hasilpanen(1) {}

// Herbivora::~Herbivora() {}

// int Herbivora::gethasilpanen() {
//     return hasilpanen;
// }

// // Karnivora class implementation
// Karnivora::Karnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location) : Animal(kodeHuruf, name, type, weightToHarvest, price, berat, location), hasilpanen(1) {}

// Karnivora::Karnivora(const Animal& other)
//     : Animal(other), hasilpanen(1) {}

// Karnivora::~Karnivora() {}

// int Karnivora::gethasilpanen() {
//     return hasilpanen;
// }

// // Omnivora class implementation
// Omnivora::Omnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
//     : Animal(kodeHuruf, name, type, weightToHarvest, price, berat, location), hasilpanen(2) {}

// Omnivora::Omnivora(const Animal& other)
//     : Animal(other), hasilpanen(1) {}

// Omnivora::~Omnivora() {}

int Omnivora::gethasilpanen() {
    return hasilpanen;
}

bool Animal::operator==(const Animal& other) const {
    return (this->kodeHuruf == other.kodeHuruf) &&
           (this->name == other.name) &&
           (this->type == other.type) &&
           (this->weightToHarvest == other.weightToHarvest) &&
           (this->price == other.price) &&
           (this->berat == other.berat) &&
           (this->location == other.location) &&
           (this->Animals == other.Animals);
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) { // check for self-assignment
        this->kodeHuruf = other.kodeHuruf;
        this->name = other.name;
        this->type = other.type;
        this->weightToHarvest = other.weightToHarvest;
        this->price = other.price;
        this->berat = other.berat;
        this->location = other.location;
        this->Animals = other.Animals;
    }
    return *this;
}
