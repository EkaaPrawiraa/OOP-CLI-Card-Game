#ifndef WORDMACHINE_HPP
#define WORDMACHINE_HPP

#include "Exception.hpp"

#include "../Menu/Menu.hpp"
#include "../Configuration/ProductConfig.hpp"
#include "../Configuration/MiscConfig.hpp"
#include "../Configuration/AnimalConfig.hpp"
#include "../Configuration/BuildingRecipeConfig.hpp"
#include "../Configuration/PlantConfig.hpp"

#include "../Utility/WordMachine.hpp"
#include "../Utility/Exception.hpp"

#include "../Role/Role.hpp"
#include "../Role/Farmer.hpp"
#include "../Role/Petani.hpp"
#include "../Role/Walikota.hpp"

#include "../item/Item.hpp"

#include "../item/Animal.hpp"

#include "../item/Plant.hpp"

#include "../item/Building.hpp"
#include "../item/Product.hpp"

#include "../color/pcolor.hpp"

#include "../Storage/Storage.hpp"
#include "../Store/Store.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>


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
    std::vector<Role*> read_input(MiscConfig misc, const std::vector<ProductConfig>& pco, const std::vector<AnimalConfig>& aco, const std::vector<PlantConfig>& plco, const std::vector<BuildingRecipeConfig> bco , Store& toko);
    std::vector<BuildingRecipeConfig> readRecipes();
    void save_input(const std::string& filename, const std::vector<Role*>& roles, const MiscConfig& misc, const std::vector<ProductConfig>& pco, const std::vector<AnimalConfig>& aco, const std::vector<PlantConfig>& plco, const std::vector<BuildingRecipeConfig>& bco, const Store& toko);
    
};

#endif 
