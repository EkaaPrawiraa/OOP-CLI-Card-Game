#include "item/FruitPlant.hpp"

FruitPlant::FruitPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location, Product hasil) 
: Plant(kodeHuruf,  name, type, durationToHarvest, price, umur, location), hasilpanen(hasil){}

FruitPlant::FruitPlant(const FruitPlant& other): Plant(other), hasilpanen(other.hasilpanen){}

FruitPlant::~FruitPlant(){}

Product* FruitPlant::gethasilpanen() {
    return &hasilpanen;
}

string FruitPlant::getclassname(){
    return "FruitPlant";
}