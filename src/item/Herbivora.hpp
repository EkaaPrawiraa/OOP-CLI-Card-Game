#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP


#include "Animal.hpp"
#include "Product.hpp"

class Herbivora : public Animal{
public:
    Herbivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location, vector<Product*> panen);
    Herbivora(const Herbivora&);
    ~Herbivora();

    string getclassname() override;
    vector<Product*> gethasilpanen(vector<ProductConfig> config)  override;


protected:
    vector<Product*> hasilpanen;
};


#endif
