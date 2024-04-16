#include "item/Animal.hpp"

// Animal class implementation
Animal::Animal(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location)
    : Item(kodeHuruf, name, price), type(type), weightToHarvest(weightToHarvest), berat(berat), location(location) {}

Animal::Animal(const Animal& other)
    : Item(other), type(other.type), weightToHarvest(other.weightToHarvest), berat(other.berat), location(other.location) {}

Animal::Animal(const std::vector<AnimalConfig>& configs, const std::string& name)
    : Item("", name, 0), type(""), weightToHarvest(0), berat(0), location("") {
    // Search for the AnimalConfig with the given name
    for (const auto& config : configs) {
        if (config.name == name) {

            kodeHuruf = config.kodeHuruf;
            type = config.type;
            weightToHarvest = config.weightToHarvest;
            berat = 0;
            location = ""; 
            price = config.price;
            break;
        }
    }
}
Animal::~Animal() {}

pair<char, int> Animal::getColumnAndRowIndex(const string& location) const{
    char column = location[0]; 
    int row = stoi(location.substr(1)); 
    return make_pair(column, row);
}

string Animal::gettype() const{
    return type;
}

int Animal::getweighttoharvest() const{
    return weightToHarvest;
}




int Animal::getberat() const{
    return berat;
}

string Animal::getlocation() {
    return location;
}
string Animal::getclassname()const{
    return "Animal";
}


bool Animal::operator==(const Animal& other) const {
    return (this->kodeHuruf == other.kodeHuruf) &&
           (this->name == other.name) &&
           (this->type == other.type) &&
           (this->weightToHarvest == other.weightToHarvest) &&
           (this->price == other.price) &&
           (this->berat == other.berat) &&
           (this->location == other.location);
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
    }
    return *this;
}

vector<Product*> Animal::gethasilpanen(vector<ProductConfig> config) {
    vector<Product*> hasilPanen;
    for (ProductConfig& P : config) {
        if (P.getorigin() == this->getname()) {
            Product* newProduct = new Product(
                P.getcode(),
                P.getname(),
                P.gettype(),
                P.getorigin(),
                P.getaddedtoweight(),
                P.getprice()
            );
            hasilPanen.push_back(newProduct);
        }
    }
    return hasilPanen;
}
void Animal::setberat(int n){
    berat=n;
}