#include "Product/Product.hpp"
#include <stdexcept>

Product::Product(){
    this->kodeHuruf="   ";
    this->name="";
    this->tipe="";
    this->origin="";

}
Product::Product(std::string kodehuruf, const std::vector<ProductConfig>& vec, std::string location) {
    bool found = false;
    for (const auto& config : vec) {
        if (config.kodeHuruf == kodehuruf) {
            found = true;
            this->kodeHuruf = config.kodeHuruf;
            this->name = config.name;
            this->tipe = config.type;
            this->origin = config.origin;
            this->added_weight = config.addedWeight;
            this->price = config.price;
            this->location = location;
            break;
        }
    }
    if (!found) {
        throw std::invalid_argument("ProductConfig with kodeHuruf " + kodehuruf + " not found");
    }
}

bool Product::operator==(const Product& other) const {
        return this->kodeHuruf == other.kodeHuruf;
    }
std::string Product::getkodeHuruf() const{
    return kodeHuruf;
}
std::string Product::getname() const{
    return name;
}
std::string Product::gettipe() const{
    return tipe;
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

