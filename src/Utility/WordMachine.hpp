#ifndef WORDMACHINE_HPP
#define WORDMACHINE_HPP

#include "Exception.hpp"
#include "..\\Plant\\Plant.hpp"
#include "..\\Animal\\Animal.hpp"
#include "..\\Product\\Product.hpp"
#include "..\\Configuration\\MiscConfig.hpp"
#include "..\\Building\\BuildingRecipe.hpp"



#include <string>
#include <vector>
#include <fstream>

class WordMachine
{
private:
    std::ifstream file;

public:
    WordMachine(const std::string &filename);
    ~WordMachine();
    std::vector<Plant> readPlants();
    std::vector<Animal> readAnimals();
    std::vector<Product> readProducts();
    MiscConfig readConfig();
    std::vector<BuildingRecipe> readRecipes();
};

#endif 
