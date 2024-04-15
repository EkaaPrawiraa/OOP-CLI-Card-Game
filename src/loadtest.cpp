// #include "Configuration/PlantConfig.hpp"
// #include "Utility/WordMachine.hpp"
// #include "Configuration/ProductConfig.hpp"
// #include "Configuration/MiscConfig.hpp"
// // #include "Configuration/BuildingRecipeConfig.hpp"
// #include "item/MaterialPlant.hpp"
// #include "item/FruitPlant.hpp"
// #include "item/Item.hpp"
// // #include "PlantAnimal/Animal.hpp"
// #include "Role/Petani.hpp"
// #include "Role/Farmer.hpp"
// #include "Store/Store.hpp"
// #include "Role/Role.hpp"
// #include <vector>
// #include <iostream>
// #include "Role/Walikota.hpp"
// int main(){
//     WordMachine machine1("Configuration//config//animal.txt");
//     WordMachine machine2("Configuration//config//plant.txt");
//     WordMachine machine3("Configuration//config//product.txt");
//     WordMachine machine4("Configuration//config//recipe.txt");
//     WordMachine machine5("Configuration//config//misc.txt");
    

//     vector<AnimalConfig> animalconfig = machine1.readAnimals();
//     vector<PlantConfig> plantconfig = machine2.readPlants();
//     vector<ProductConfig>productconfig = machine3.readProducts();
//     vector<BuildingRecipeConfig> buildingconfig =machine4.readRecipes();
//     MiscConfig miscconfig =machine5.readConfig();
//     std::vector<Plant> plants;
//     plants.emplace_back("P1", "Tree", "Oak", 10, 50, 5, "A1");
//     plants.emplace_back("P2", "Flower", "Rose", 5, 30, 2, "A2");

//     std::vector<Animal> animals;
//     animals.emplace_back("A1", "Dog", "Mammal", 20, 100, 15, "B1");
//     animals.emplace_back("A2", "Cat", "Mammal", 15, 80, 10, "B2");
//     Store Toko(plants, animals);
//     int targetGulden = miscconfig.getWinningMoney();
//     int targetWeight = miscconfig.getWinningWeight();

//     for (AnimalConfig a: animalconfig){
//         a.display();
//     }
//     std::string file;
//     cout<<"Masukkan file yang ingin dimuat: ";
//     cin>>file;
//     WordMachine machineload(file);
//     std::vector<Role*> Players=machineload.read_input(miscconfig, productconfig, animalconfig, plantconfig, buildingconfig, Toko);
//     cout<<"AS"<<endl;
//     std::cout<<Players[0]->getUsername()<<endl;
//     cout<<"TE"<<endl;
//     Players[0]->cetak_penyimpanan();
//     Toko.display();
//     Farmer* farmer = static_cast<Farmer*>(Players[0]);
//     farmer->membeli(Toko);
//     cout<<"Masukkan file yang ingin disave: ";
//     cin>>file;
//     machineload.save_input(file, Players, miscconfig, productconfig, animalconfig, plantconfig, buildingconfig, Toko);
    

//     return 0;
// }