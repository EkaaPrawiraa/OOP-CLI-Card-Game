#ifndef FRUITPLANT_HPP
#define FRUITPLANT_HPP

#include "Plant.hpp"
#include "Product.hpp"
class FruitPlant : public Plant {
    public:
        FruitPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location, Product hasil);
        FruitPlant(const FruitPlant&);
        ~FruitPlant();

        Product* gethasilpanen()  override;
        string getclassname() override;


    private:
        Product hasilpanen;
};


#endif