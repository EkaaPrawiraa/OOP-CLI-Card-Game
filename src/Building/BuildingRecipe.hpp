#ifndef BUILDINGRECIPE_HPP
#define BUILDINGRECIPE_HPP

#include <string>
#include <vector>

struct Material
{
    std::string name;
    int quantity;

    Material(const std::string &name, int quantity);
};

class BuildingRecipe
{
public:
    int id;
    std::string kodeHuruf;
    std::string name;
    int price;
    std::vector<Material> materials;

    BuildingRecipe(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials);
    void display() const;
};

#endif
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE