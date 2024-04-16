#ifndef MENU_HPP
#define MENU_HPP


#include <fstream>
#include <vector>
#include <iostream>
#include <string>

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

using namespace std;

class Menu {
private:
    

public:

// startGame
    Menu();
    vector<PlantConfig> LoadPlantConfig();
    vector<AnimalConfig> LoadAnimalConfig();
    vector<ProductConfig> LoadProductConfig();
    vector<MiscConfig> LoadMiscConfig();
    vector<BuildingRecipeConfig> LoadBuildingRecipeConfig();

    vector<Role> urutPlayer(vector<Role>&);

    // opsi baca dari state atau mulai manual
    int mulai();

    int listmenu();
// inGame
    void Continue();
    void run();
    Role* Next();
    void cetak_penyimpanan();
// endGame
    bool isWinner(Role* Player);
    


};

#endif // MENU_HPP
