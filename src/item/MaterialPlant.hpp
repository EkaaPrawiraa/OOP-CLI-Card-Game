#ifndef MATERIALPLANT_HPP
#define MATERIALPLANT_HPP

#include "Plant.hpp"
#include "Product.hpp"
class MaterialPlant : public Plant {
    public:
        MaterialPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location, Product hasil);
        MaterialPlant(const MaterialPlant&);
        ~MaterialPlant();

        Product* gethasilpanen()  override;
        string getclassname() override;


    private:
        Product hasilpanen;
};


#endif