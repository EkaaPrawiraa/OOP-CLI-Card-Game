#ifndef BUILDINGRECIPE_HPP
#define BUILDINGRECIPE_HPP

#include <string>
#include <vector>
#include <tuple>

using namespace std;

class BuildingRecipeConfig
{
public:
    BuildingRecipeConfig(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::tuple<std::string, int> > &materials);
    void display() const;
    int getid();
    std::string getcode();
    std::string getname();
    int getprice();
    std::vector<std::tuple<std::string, int> > getmaterials();

private:
    int id;
    std::string kodeHuruf;
    std::string name;
    int price;
    std::vector<std::tuple<std::string, int> > materials;
};

#endif
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE