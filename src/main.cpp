#include "Configuration/PlantConfig.hpp"
#include "Utility/WordMachine.hpp"
#include "Configuration/ProductConfig.hpp"
#include "Configuration/MiscConfig.hpp"
// #include "Configuration/BuildingRecipeConfig.hpp"
#include "item/Plant.hpp"
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
    // std::vector<Product> products = machine.readProducts();

    // for (const auto &product : products)
    // {
    //     product.display();
    // }

    // ---------Animal-------------//
    // std::vector<Animal> animals = machine.readAnimals();

    // for (const auto &animal : animals)
    // {
    //     animal.display();

    // ---------Plants-------------//

    std::vector<PlantConfig> plants = machine.readPlants();
    Plant* sample = new Plant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C02");
    Plant* sample1 = new Plant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C03");
    Plant* sample2 = new Plant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C04");
    Plant* sample3 = new Plant(plants.at(1).getcode(), plants.at(1).getname(), plants.at(1).gettype(), plants.at(1).getdurationtoharvest(), plants.at(1).getprice(), 2, "A04");
    Petani p1("Cupi", 5.0, 50, 10, 10, 8,8);
    p1.setLadang(2, 'C', sample);
    p1.setLadang(3, 'C', sample1);
    p1.setLadang(4, 'C', sample2);
    p1.setLadang(4, 'A', sample3);
    p1.CetakLadang();
    p1.Memanen();
    p1.CetakLadang();
    
    p1.cetak_penyimpanan();
    // for (const auto &plant : plants)
    // {
    //     plant.display();
    // }
    // return 0;

}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE