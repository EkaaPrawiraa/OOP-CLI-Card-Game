#include "Configuration\PlantConfig.hpp"
#include "Utility\WordMachine.hpp"
#include "Configuration\ProductConfig.hpp"
#include "Configuration\MiscConfig.hpp"
#include "Configuration\BuildingRecipeConfig.hpp"
#include "PlantAnimal/Plant.hpp"
// #include "PlantAnimal/Animal.hpp"
#include "Role/Petani.hpp"
// #include "Role/Farmer.hpp"
#include "Storage.hpp"
#include <vector>
#include <iostream>
using namespace std;

// g++ - o test main.cpp WordMachine.cpp AnimalConfig.cpp PlantConfig.cpp ProductConfig.cpp MiscConfig.cpp BuildingRecipeConfig.cpp

int main()
{
    WordMachine machine("Configuration\\config\\plant.txt");

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
    Plant sample(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest()-2, plants.at(0).getprice(), 2, "C02");
    std::vector<Plant> plant;
    plant.push_back(sample);

    Matrix invent(5,5);
    Matrix p(8,8);//Matriks Ladang
    Petani p1("Cupi", 5.0, 50, invent, plant, p);
    p1.setMatrix();
    p1.CetakLadang();
    // for (const auto &plant : plants)
    // {
    //     plant.display();
    // }
    // return 0;

}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE