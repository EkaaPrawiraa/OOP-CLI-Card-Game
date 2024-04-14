#ifndef MENU_HPP
#define MENU_HPP

// #include <iostream>
// #include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "../Configuration/PlantConfig.hpp"
#include "../Utility/WordMachine.hpp"
#include "../Configuration/ProductConfig.hpp"
#include "../Configuration/MiscConfig.hpp"
#include "../Configuration/AnimalConfig.hpp"
#include "../Configuration/BuildingRecipeConfig.hpp"
using namespace std;

class Menu {
private:
    // std::ifstream inFile;
    // std::ofstream outFile;

public:
    Menu();
    vector<PlantConfig> LoadPlantConfig();
    vector<AnimalConfig> LoadAnimalConfig();
    vector<ProductConfig> LoadProductConfig();
    vector<MiscConfig> LoadMiscConfig();
    vector<BuildingRecipeConfig> LoadBuildingRecipeConfig();
    int mulai();
    int listmenu();

    void Continue();
    void run();
};

#endif // MENU_HPP
