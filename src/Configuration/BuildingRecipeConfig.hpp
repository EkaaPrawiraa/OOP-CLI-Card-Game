#ifndef BUILDINGRECIPECONFIG_HPP
#define BUILDINGRECIPECONFIG_HPP

#include <string>
#include <vector>

class BuildingRecipeConfig {
public:
    BuildingRecipeConfig(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::pair<std::string, int>> &materials);
    void display() const;
    int getid() const;
    std::string getcode() const;
    std::string getname() const;
    int getprice() const;
    std::vector<std::pair<std::string, int>> getmaterials() const;

private:
    int id;
    std::string kodeHuruf;
    std::string name;
    int price;
    std::vector<std::pair<std::string, int>> materials;
};

#endif
