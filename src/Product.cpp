#include "item/Product.hpp"
#include <stdexcept>


Product::Product(const string &kodeHuruf,const string &name, const string &type, const string &origin, int added_weight, int price) : Item(kodeHuruf, name, price), type(type), added_weight(added_weight), origin(origin) {}

Product::Product(const Product& other)
    : Item(other), type(other.type), added_weight(other.added_weight), origin(other.origin) {}

Product::~Product() {}

bool Product::operator==(const Product& other) const {
        return this->kodeHuruf == other.kodeHuruf;
    }

std::string Product::gettipe() const{
    return type;
}
std::string Product::getorigin() const{
    return origin;
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

string Product::getclassname(){
    return "Product";
}

