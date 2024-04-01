#include "Configuration\PlantConfig.hpp"
#include "Utility\WordMachine.hpp"
#include "Configuration\ProductConfig.hpp"
#include "Configuration\MiscConfig.hpp"
#include "Configuration\BuildingRecipeConfig.hpp"
#include <vector>
#include <iostream>
using namespace std;

// g++ - o test main.cpp WordMachine.cpp Animal.cpp Plant.cpp Product.cpp MiscConfig.cpp BuildingRecipe.cpp

int main()
{
    WordMachine machine("Configuration\\config\\recipe.txt");

    std::vector<BuildingRecipeConfig> recipes = machine.readRecipes();

    for (const auto &recipe : recipes)
    {
        recipe.display();
        std::cout << "------------------------" << std::endl;
    }
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

    // std::vector<Plant> plants = machine.readPlants();

    // for (const auto &plant : plants)
    // {
    //     plant.display();
    // }
    return 0;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE