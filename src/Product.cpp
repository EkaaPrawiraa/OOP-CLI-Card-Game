#include "item/Product.hpp"
#include <stdexcept>


Product::Product(const string &kodeHuruf,const string &name, const string &type, const string &origin, int added_weight, int price, const string &location) : Item(kodeHuruf, name, price), type(type), added_weight(added_weight), origin(origin), location(location) {}

Product::Product(const Product& other)
    : Item(other), type(other.type), added_weight(other.added_weight), origin(other.origin), location(other.location) {}

Product::~Product() {}

std::string Product::getkodeHuruf() const{
    return kodeHuruf;
}
std::string Product::getname() const{
    return name;
}
bool Product::operator==(const Product& other) const {
        return this->kodeHuruf == other.kodeHuruf;
    }

std::string Product::gettipe() const{
    return type;
}
std::string Product::getorigin() const{
    return origin;
}
std::string Product::getlocation() const{
    return location;
}
int Product::getadded_weight() const{
    return added_weight;
}
int Product::getprice() const{
    return price;
}
pair<char, int> Product::getColumnAndRowIndex(const string& location) const{
    char column = location[0]; 
    int row = stoi(location.substr(1)); 
    return make_pair(column, row);
}
bool Product::operator==(const Product& other) const {
    return (this->kodeHuruf == other.kodeHuruf &&
            this->name == other.name &&
            this->tipe == other.tipe &&
            this->origin == other.origin &&
            this->added_weight == other.added_weight &&
            this->price == other.price);
}
Product& Product::operator=(const Product& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    this->kodeHuruf = other.kodeHuruf;
    this->name = other.name;
    this->tipe = other.tipe;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
    this->price = other.price;

    return *this;
}
