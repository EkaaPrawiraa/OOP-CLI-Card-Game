#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP


#include "Animal.hpp"
#include "Product.hpp"

class Omnivora : public Animal{
public:
    Omnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location,  vector<Product*>  panen);
    Omnivora(const Omnivora&);
    ~Omnivora();
    
    string getclassname() override;
    vector<Product*> gethasilpanen()  override;


protected:
    vector<Product*> hasilpanen;
};


#endif
