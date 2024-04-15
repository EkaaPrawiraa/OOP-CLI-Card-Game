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
#include "Role/Farmer.hpp"
#include "Store/Store.hpp"
#include "Role/Role.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Role/Walikota.hpp"
#include <string>

std::vector<Role*> read_input(const std::string& filename, MiscConfig misc, const std::vector<ProductConfig>& pco, const std::vector<AnimalConfig>& aco, const std::vector<PlantConfig>& plco, const std::vector<BuildingRecipeConfig> bco ) {
    std::vector<Role*> roles;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return roles;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int loopa;
        iss>>loopa;
        std::string username;
        for (int k=0;k<loopa;++k)
            iss >> username;
            std::string role_type;
            iss >> role_type;
            if (role_type == "Petani") {
                std::string lokasi;            float weight;
                int money, storrows, storcols, ladrows, ladcols, loop, umur;
                storrows = misc.getStorageRows();
                storcols = misc.getStorageCols();
                ladrows = misc.getLandRows();
                ladcols = misc.getLandCols();
                iss >> weight >> money;
                Petani* petani = new Petani(username, weight, money, storrows, storcols, ladrows, ladcols);
                iss >> loop;
                std::string itemsname;
                // Read ladang
                for (int i = 0; i < loop; ++i) {
                    iss>>itemsname;
                    Item* p = Item::createItem(pco, plco, aco, bco, itemsname);
                    petani->getInventory().setfirstempty(p);
                }
                iss >> loop;
                for (int i=0; i< loop; ++i){
                    iss>>lokasi>>itemsname>>umur;
                    char col = lokasi[0];
                    int row = stoi(lokasi.substr(1));
                    Item* q = Item::createItem(pco, plco, aco, bco, itemsname);
                    if (auto plant = dynamic_cast<Plant *>(q)){
                        petani->setLadang(row, col, plant);
                    }
                }

                roles.push_back(petani);
            } else if (role_type == "Peternak") {
                std::string username, lokasi;            float weight;
                int money, storrows, storcols, ladrows, ladcols, loop, umur;
                storrows = misc.getStorageRows();
                storcols = misc.getStorageCols();
                ladrows = misc.getFarmRows();
                ladcols = misc.getFarmCols();
                iss >> weight >> money;
                Farmer* petani = new Farmer(username, weight, money, storrows, storcols, ladrows, ladcols);
                iss >> loop;
                std::string itemsname;
                // Read ladang
                for (int i = 0; i < loop; ++i) {
                    iss>>itemsname;
                    Item* p = Item::createItem(pco, plco, aco, bco, itemsname);
                    petani->getInventory().setfirstempty(p);
                }
                iss >> loop;
                for (int i=0; i< loop; ++i){
                    iss>>lokasi>>itemsname>>umur;
                    char col = lokasi[0];
                    int row = stoi(lokasi.substr(1));
                    Item* q = Item::createItem(pco, plco, aco, bco, itemsname);
                    if (auto plant = dynamic_cast<Animal *>(q)){
                        petani->setTernak(row, col, plant);
                    }
                }
                // Similar logic for Farmer class
                // Implement it similarly to Petani
            } else if (role_type == "Walikota") {
                std::string username, lokasi;            float weight;
                int money, storrows, storcols, loop, umur;
                storrows = misc.getStorageRows();
                storcols = misc.getStorageCols();
                iss >> weight >> money;
                Walikota* petani = &Walikota::conditionalConstructor(username, weight, money, storrows, storcols);
                iss >> loop;
                std::string itemsname;
                // Read ladang
                for (int i = 0; i < loop; ++i) {
                    iss>>itemsname;
                    Item* p = Item::createItem(pco, plco, aco, bco, itemsname);
                    petani->getInventory().setfirstempty(p);
                }
                // Similar logic for Walikota class
                // Implement it similarly to Petani
            }
    }

    file.close();
    return roles;
}