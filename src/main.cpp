#include "Configuration/PlantConfig.hpp"
#include "Utility/WordMachine.hpp"
#include "Configuration/ProductConfig.hpp"
#include "Configuration/MiscConfig.hpp"
// #include "Configuration/BuildingRecipeConfig.hpp"
#include "item/MaterialPlant.hpp"
#include "item/FruitPlant.hpp"
#include "item/Item.hpp"
// #include "PlantAnimal/Animal.hpp"
#include "Role/Petani.hpp"
// #include "Role/Farmer.hpp"
#include "Role/Role.hpp"
#include <vector>
#include <iostream>
using namespace std;

// g++ -o test main.cpp WordMachine.cpp AnimalConfig.cpp PlantConfig.cpp ProductConfig.cpp MiscConfig.cpp BuildingRecipeConfig.cpp

int main()
{
    WordMachine machine("Configuration//config//plant.txt");
    WordMachine machine1("Configuration//config//product.txt");

    // std::vector<BuildingRecipeConfig> recipes = machine.readRecipes();

    // for (const auto &recipe : recipes)
    // {
    //     recipe.display();
    //     std::cout << "------------------------" << std::endl;
    // }
    // ---------config-------------//
    // MiscConfig config = machine.readConfig();

    // config.display();

    // ---------Product-------------//
    std::vector<ProductConfig> products = machine1.readProducts();
    Product pr(products.at(0).getcode(), products.at(0).getname(), products.at(0).gettype(), products.at(0).getorigin(), products.at(0).getaddedtoweight(), products.at(0).getprice());
    Product pr1(products.at(4).getcode(), products.at(4).getname(), products.at(4).gettype(), products.at(4).getorigin(), products.at(4).getaddedtoweight(), products.at(4).getprice());

    // ---------Animal-------------//
    // std::vector<Animal> animals = machine.readAnimals();

    // for (const auto &animal : animals)
    // {
    //     animal.display();

    // ---------Plants-------------//

    std::vector<PlantConfig> plants = machine.readPlants();

    MaterialPlant* sample = new MaterialPlant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C02", pr);
    MaterialPlant* sample1 = new MaterialPlant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "A04", pr);
    MaterialPlant* sample2 = new MaterialPlant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C04", pr);
    FruitPlant* sample3 = new FruitPlant(plants.at(4).getcode(), plants.at(4).getname(), plants.at(4).gettype(), plants.at(4).getdurationtoharvest(), plants.at(4).getprice(), 10, "C03", pr1);
    Petani p1("Cupi", 5.0, 50, 10, 10, 8,8);
    p1.setLadang(2, 'C', sample);
    p1.setLadang(4, 'A', sample1);
    p1.setLadang(4, 'C', sample2);
    p1.setLadang(3, 'C', sample3);
    p1.CetakLadang();
    p1.Tanam();
    p1.Memanen();
    p1.CetakLadang();
    p1.cetak_penyimpanan();
    
    // p1.cetak_penyimpanan();
    // for (const auto &plant : plants)
    // {
    //     plant.display();
    // }
    // return 0;

}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE