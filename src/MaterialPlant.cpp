#include "item/MaterialPlant.hpp"

MaterialPlant::MaterialPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location, Product hasil) 
: Plant(kodeHuruf,  name, type, durationToHarvest, price, umur, location), hasilpanen(hasil){}

MaterialPlant::MaterialPlant(const MaterialPlant& other): Plant(other), hasilpanen(other.hasilpanen){}

MaterialPlant::~MaterialPlant(){}

Product* MaterialPlant::gethasilpanen() {
    return &hasilpanen;
}

string MaterialPlant::getclassname(){
    return "MaterialPlant";
}