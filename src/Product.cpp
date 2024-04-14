#include "item/Product.hpp"
#include <stdexcept>

Product::Product(const std::string &kodeHuruf, const std::string &name, const std::string &type, const std::string &origin, int added_weight, int price) 
    : Item(kodeHuruf, name, price), type(type), added_weight(added_weight), origin(origin) {}

Product::Product(const Product& other)
    : Item(other), type(other.type), added_weight(other.added_weight), origin(other.origin) {}

Product::~Product() {}

<<<<<<< Updated upstream


std::string Product::gettipe() const{
=======
std::string Product::gettipe() const {
>>>>>>> Stashed changes
    return type;
}

std::string Product::getorigin() const {
    return origin;
}

int Product::getadded_weight() const {
    return added_weight;
}

<<<<<<< Updated upstream
pair<char, int> Product::getColumnAndRowIndex(const string& location) const{
=======
int Product::getprice() const {
    return price;
}


std::pair<char, int> Product::getColumnAndRowIndex(const std::string& location) const {
>>>>>>> Stashed changes
    char column = location[0]; 
    int row = std::stoi(location.substr(1)); 
    return std::make_pair(column, row);
}
<<<<<<< Updated upstream
// bool Product::operator==(const Product& other) const {
//     return (this->kodeHuruf == other.kodeHuruf &&
//             this->name == other.name &&
//             this->type == other.type &&
//             this->origin == other.origin &&
//             this->added_weight == other.added_weight &&
//             this->price == other.price);
// }
=======

bool Product::operator==(const Product& other) const {
    return (this->kodeHuruf == other.kodeHuruf &&
            this->name == other.name &&
            this->type == other.type &&
            this->origin == other.origin &&
            this->added_weight == other.added_weight &&
            this->price == other.price);
}

>>>>>>> Stashed changes
Product& Product::operator=(const Product& other) {
    if (this == &other) {
        return *this; 
    }

    this->kodeHuruf = other.kodeHuruf;
    this->name = other.name;
    this->type = other.type;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
    this->price = other.price;

    return *this;
}

std::string Product::getclassname() {
    return "Product";
}
