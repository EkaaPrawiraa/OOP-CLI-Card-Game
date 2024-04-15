#include "item/Omnivora.hpp"

Omnivora::Omnivora(const string &kodeHuruf,const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location,  vector<Product*>  hasil) 
: Animal(kodeHuruf,  name, type, weightToHarvest, price, berat, location), hasilpanen(hasil){}

Omnivora::Omnivora(const Omnivora& other): Animal(other), hasilpanen(other.hasilpanen){}

Omnivora::~Omnivora(){}

vector<Product*> Omnivora::gethasilpanen(vector<ProductConfig> config) {
    vector<Product*> hasilPanen;
    for (ProductConfig& P : config) {
        if (P.getorigin() == this->getKode()) {
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

string Omnivora::getclassname(){
    return "Omnivora";
}
