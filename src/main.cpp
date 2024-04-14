#include "Configuration/PlantConfig.hpp"
#include "Utility/WordMachine.hpp"
#include "Configuration/ProductConfig.hpp"
#include "Configuration/MiscConfig.hpp"
// #include "Configuration/BuildingRecipeConfig.hpp"
#include "item/MaterialPlant.hpp"
#include "item/FruitPlant.hpp"
#include "item/Item.hpp"
// #include "PlantAnimal/Animal.hpp"
// #include "Role/Petani.hpp"
// #include "Role/Farmer.hpp"
#include "Role/Role.hpp"
#include <vector>
#include <iostream>

using namespace std;

//  g++ -o test main.cpp Animal.cpp Building.cpp Store.cpp Plant.cpp Product.cpp
int main()
{
    WordMachine machine("Configuration//config//plant.txt");
    WordMachine machine1("Configuration//config//product.txt");

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
    std::vector<ProductConfig> products = machine1.readProducts();
    Product pr(products.at(0).getcode(), products.at(0).getname(), products.at(0).gettype(), products.at(0).getorigin(), products.at(0).getaddedtoweight(), products.at(0).getprice());
    Product pr1(products.at(4).getcode(), products.at(4).getname(), products.at(4).gettype(), products.at(4).getorigin(), products.at(4).getaddedtoweight(), products.at(4).getprice());

    // ---------Animal-------------//
    // std::vector<Animal> animals = machine.readAnimals();

    // for (const auto &animal : animals)
    // {
    //     animal.display();

    // ---------Plants-------------//

    std::vector<PlantConfig> plants = machine.readPlants();

    MaterialPlant* sample = new MaterialPlant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C02", pr);
    MaterialPlant* sample1 = new MaterialPlant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "A04", pr);
    MaterialPlant* sample2 = new MaterialPlant(plants.at(0).getcode(), plants.at(0).getname(), plants.at(0).gettype(), plants.at(0).getdurationtoharvest(), plants.at(0).getprice(), 15, "C04", pr);
    FruitPlant* sample3 = new FruitPlant(plants.at(4).getcode(), plants.at(4).getname(), plants.at(4).gettype(), plants.at(4).getdurationtoharvest(), plants.at(4).getprice(), 10, "C03", pr1);
    Petani p1("Cupi", 5.0, 50, 10, 10, 8,8);
    p1.setLadang(2, 'C', sample);
    p1.setLadang(4, 'A', sample1);
    p1.setLadang(4, 'C', sample2);
    p1.setLadang(3, 'C', sample3);
    p1.CetakLadang();
    p1.Tanam();
    p1.Memanen();
    p1.CetakLadang();
    p1.cetak_penyimpanan();
    
    // p1.cetak_penyimpanan();
    // for (const auto &plant : plants)
    // {
    //     plant.display();
    // }
    // return 0;

    //  ----------Store---------//
    std::vector<Plant> plants;
    plants.emplace_back("P1", "Tree", "Oak", 10, 50, 5, "A1");
    plants.emplace_back("P2", "Flower", "Rose", 5, 30, 2, "A2");

    std::vector<Animal> animals;
    animals.emplace_back("A1", "Dog", "Mammal", 20, 100, 15, "B1");
    animals.emplace_back("A2", "Cat", "Mammal", 15, 80, 10, "B2");

    std::vector<Product> products;
    products.emplace_back("Prod2", "Book", "Stationery", "Local", 0, 20);
    products.emplace_back("Prod2", "Pen", "Stationery", "Imported", 0, 10);

    std::vector<Building> buildings;

    // buildings.emplace_back("B1", "House", 100, std::vector<std::pair<std::string, int> >{ {"Wood", 50}, {"Stone", 20} });
    // buildings.emplace_back("B2", "Shop", 200, std::vector<std::pair<std::string, int> >{{"Wood", 30}, {"Glass", 10}});
    // buildings.emplace_back("B3", "School", 500, std::vector<std::pair<std::string, int> >{{"Brick", 200}});

   
   Product test("A3", "budi", "Mammal", "20", 100, 15);
    Store store1(buildings, plants, animals, products);

    // store1.display();
    Farmer farmer("John", 1000, 70.5, 8, 8, 6, 6);
    farmer.membeli(store1);
    Product* testPtr = &test;
    Matrix<Item*> &inv=farmer.getInventory();
    inv.setValue(1,'B',testPtr);
    cout<<inv.getValue(1,'B')->getKode()<<endl;
    // farmer.cetak_penyimpanan();
    farmer.menjual(store1);
    
    // farmer.cetak_penyimpanan();
    store1.display();
    return 0;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE