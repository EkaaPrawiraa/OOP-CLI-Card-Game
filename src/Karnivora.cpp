#include "item/Karnivora.hpp"

Karnivora::Karnivora(const string &kodeHuruf,const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location, vector<Product*> hasil) 
: Animal(kodeHuruf,  name, type, weightToHarvest, price, berat, location), hasilpanen(hasil){}

Karnivora::Karnivora(const Karnivora& other): Animal(other), hasilpanen(other.hasilpanen){}

Karnivora::~Karnivora(){}

vector<Product*> Karnivora::gethasilpanen(vector<ProductConfig> config) {
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

string Karnivora::getclassname(){
    return "Karnivora";
}