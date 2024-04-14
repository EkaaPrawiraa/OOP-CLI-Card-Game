#include "item/Plant.hpp"

// Plant class implementation
Plant::Plant(const string &kodeHuruf, const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location)
    : Item(kodeHuruf, name, price), type(type), durationToHarvest(durationToHarvest), umur(umur), location(location) {}

Plant::Plant(const Plant& other)
    : Item(other), type(other.type), durationToHarvest(other.durationToHarvest), umur(other.umur), location(other.location) {}

Plant::~Plant() {}

string Plant::gettype() const{
    return type;
}

int Plant::getdurationtoharvest() const{
    return durationToHarvest;
}



string Plant::getlocation() const {
    return location;
}

int Plant::getumur() const {
    return umur;
}


pair<char, int> Plant::getColumnAndRowIndex(const string& location) const{
    char column = location[0]; 
    int row = stoi(location.substr(1)); 
    return make_pair(column, row);
}
string Plant::getclassname(){
    return "Plant";
}




// bool Plant::operator==(const Plant& other) const {
//     return (this->kodeHuruf == other.kodeHuruf) &&
//            (this->name == other.name) &&
//            (this->type == other.type) &&
//            (this->durationToHarvest == other.durationToHarvest) &&
//            (this->price == other.price) &&
//            (this->umur == other.umur) &&
//            (this->location == other.location) &&
//            (this->Plants == other.Plants);
// }

<<<<<<< Updated upstream
// Plant& Plant::operator=(const Plant& other) {
//     if (this != &other) { // check for self-assignment
//         this->kodeHuruf = other.kodeHuruf;
//         this->name = other.name;
//         this->type = other.type;
//         this->durationToHarvest = other.durationToHarvest;
//         this->price = other.price;
//         this->umur = other.umur;
//         this->location = other.location;
//         this->Plants = other.Plants;
//     }
//     return *this;
=======
// // FruitPlant class implementation
// FruitPlant::FruitPlant(const string &kodeHuruf, const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location)
//     : Plant(kodeHuruf, name, type, durationToHarvest, price, umur, location), hasilpanen(1) {}

// int FruitPlant::gethasilpanen() {
//     return hasilpanen;
// }
bool Plant::operator==(const Plant& other) const {
    return (this->kodeHuruf == other.kodeHuruf) &&
           (this->name == other.name) &&
           (this->type == other.type) &&
           (this->durationToHarvest == other.durationToHarvest) &&
           (this->price == other.price) &&
           (this->umur == other.umur) &&
           (this->location == other.location);
}

Plant& Plant::operator=(const Plant& other) {
    if (this != &other) { // check for self-assignment
        this->kodeHuruf = other.kodeHuruf;
        this->name = other.name;
        this->type = other.type;
        this->durationToHarvest = other.durationToHarvest;
        this->price = other.price;
        this->umur = other.umur;
        this->location = other.location;
    }
    return *this;
}
// FruitPlant::FruitPlant(const Plant& other)
//     : Plant(other), hasilpanen(1) {}

// FruitPlant::~FruitPlant() {}

// int FruitPlant::gethasilpanen() {
//     // if (name == "Teak_Tree") {
//     //     return 1;
//     // } else if (name == "Sandalwood_Tree") {
//     //     return 1;
//     // } else if (name == "Aloe_Tree") {
//     //     return 1;
//     // } else if (name == "Ironwood_Tree") {
//     //     return 1;
//     // }
//     return hasilpanen;
>>>>>>> Stashed changes
// }
