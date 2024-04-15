#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include "../Configuration/AnimalConfig.hpp"
#include "../Configuration/BuildingRecipeConfig.hpp"
#include "../Configuration/PlantConfig.hpp"
#include "../Configuration/ProductConfig.hpp"
// #include "Animal.hpp"
// #include "Plant.hpp"
// #include "Building.hpp"
// #include "Product.hpp"

using namespace std;
class Item {
    public:
        Item(const string &kodeHuruf,const string &name, int price);
        Item(const Item&);
        Item();
        // static Item* createItem(const std::vector<ProductConfig>& productConfigs, const std::vector<PlantConfig>& plantConfigs, const std::vector<AnimalConfig>& animalConfigs, const std::vector<BuildingRecipeConfig>& buildingConfigs, const std::string& itemName);
        virtual ~Item();
        virtual string getclassname();
        string getname() const;
        string getKode() const;
        int getprice() const;

        // kurang set

    protected:
        string kodeHuruf;
        string name;
        int price;
};

#endif