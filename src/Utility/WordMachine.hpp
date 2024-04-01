#ifndef WORDMACHINE_HPP
#define WORDMACHINE_HPP

#include "Exception.hpp"
#include "..\\Configuration\\PlantConfig.hpp"
#include "..\\Configuration\\AnimalConfig.hpp"
#include "..\\Configuration\\ProductConfig.hpp"
#include "..\\Configuration\\MiscConfig.hpp"
#include "..\\Configuration\\BuildingRecipeConfig.hpp"

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
    std::vector<PlantConfig> readPlants();
    std::vector<AnimalConfig> readAnimals();
    std::vector<ProductConfig> readProducts();
    MiscConfig readConfig();
    std::vector<BuildingRecipeConfig> readRecipes();
};

#endif 
