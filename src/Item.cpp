#include "item/Item.hpp"

// Plant class implementation
Item::Item(const string &kodeHuruf, const string &name, int price)
    : kodeHuruf(kodeHuruf), name(name), price(price) {}

Item::Item(const Item& other)
    : kodeHuruf(other.kodeHuruf), name(other.name), price(other.price) {}

Item::~Item() {}

string Item::getname() const {
    return name;
}

string Item::getKode() const{
    return kodeHuruf;
}

int Item::getprice() const{
    return price;
}
string Item::getclassname(){
    return "Item";
}
Item::Item()
{
    name="";
    kodeHuruf="";
    price=0;
}
Item* Item::createItem(const std::vector<ProductConfig>& productConfigs, const std::vector<PlantConfig>& plantConfigs, const std::vector<AnimalConfig>& animalConfigs, const std::vector<BuildingRecipeConfig>& buildingConfigs, const std::string& itemName) {
    // Check if the item name matches any of the subclasses and create the corresponding object
    for (const auto& productConfig : productConfigs) {
        if (productConfig.getname() == itemName) {
            return new Product(productConfig.getcode(), productConfig.getname(), productConfig.gettype(), productConfig.getorigin(), productConfig.getaddedtoweight(), productConfig.getprice());
        }
    }
    for (const auto& plantConfig : plantConfigs) {
        if (plantConfig.getname() == itemName) {
            return new Plant(plantConfig.getcode(), plantConfig.getname(), plantConfig.gettype(), plantConfig.getdurationtoharvest(), plantConfig.getprice(), 0, " ");
        }
    }
    for (const auto& animalConfig : animalConfigs) {
        if (animalConfig.getname() == itemName) {
            return new Animal(animalConfig.getcode(), animalConfig.getname(), animalConfig.gettype(), animalConfig.getweighttoharvest(), animalConfig.getprice(), 0, "");
        }
    }
    for (const auto& buildingConfig : buildingConfigs) {
        if (buildingConfig.getname() == itemName) {
            return new Building(buildingConfig.getcode(), buildingConfig.getname(),  buildingConfig.getprice(), buildingConfig.getmaterials());
        }
    }
    
    // Item name does not match any subclass
    return nullptr;
}

