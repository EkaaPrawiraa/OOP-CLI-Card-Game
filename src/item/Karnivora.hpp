#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP


#include "Animal.hpp"
#include "Product.hpp"

class Karnivora : public Animal{
public:
    Karnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location, vector<Product*> panen);
    Karnivora(const Karnivora&);
    ~Karnivora();
    
    string getclassname() override;
    vector<Product*> gethasilpanen(vector<ProductConfig> config)  override;


protected:
    vector<Product*> hasilpanen;
};


#endif
