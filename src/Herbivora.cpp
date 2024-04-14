#include "item/Herbivora.hpp"

Herbivora::Herbivora(const string &kodeHuruf,const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location, vector<Product*> hasil) 
: Animal(kodeHuruf,  name, type, weightToHarvest, price, berat, location), hasilpanen(hasil){}

Herbivora::Herbivora(const Herbivora& other): Animal(other), hasilpanen(other.hasilpanen){}

Herbivora::~Herbivora(){}

vector<Product*> Herbivora::gethasilpanen() {
    return hasilpanen;
}

string Herbivora::getclassname(){
    return "Herbivora";
}