#include "Plant\Plant.hpp"
#include "Utility\WordMachine.hpp"
#include "Product\Product.hpp"
#include "Configuration\MiscConfig.hpp"
#include "Building\BuildingRecipe.hpp"
#include <vector>
#include <iostream>
using namespace std;

// g++ - o test main.cpp WordMachine.cpp Animal.cpp Plant.cpp Product.cpp MiscConfig.cpp BuildingRecipe.cpp

int main()
{
    WordMachine machine("Configuration\\config\\recipe.txt");
    std::vector<BuildingRecipe> recipes = machine.readRecipes();

    for (const auto &recipe : recipes)
    {
        recipe.display();
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE