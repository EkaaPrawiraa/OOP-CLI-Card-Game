#ifndef Building_HPP
#define Building_HPP

#include "Item.hpp"
#include <vector>

struct Material
{
    std::string name;
    int quantity;

    Material(const std::string &name, int quantity);
};

class Building : public Item {
    public:
        Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials);
        Building(const Building&);
        ~Building();
        std::string getclassname(){
            return "Building";
        }
        std::vector<Material> getmaterials();

    private:
        std::vector<Material> materials;
};


#endif