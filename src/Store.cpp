#include "Store\Store.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

Store::Store(){}
Store::Store(const vector<Building> &buildings,const vector<Plant> &plants,const vector<Animal> &animals,const vector<Product> &products)
{
    this->buildings=buildings;
    this->plants=plants;
    this->animals=animals;
    this->products=products;
}

Store::~Store(){}

void Store::addBuilding(const Building addedBuilding)
{
    buildings.push_back(addedBuilding);
}
void Store::addPlant(const Plant addedPlant)
{
    plants.push_back(addedPlant);
}
void Store::addAnimal(const Animal addedAnimal)
{
    animals.push_back(addedAnimal);
}
void Store::addProduct(const Product addedProduct)
{
    products.push_back(addedProduct);
}
void Store::deleteBuilding(const Building deletedBuilding)
{
    auto it = std::find(buildings.begin(), buildings.end(), deletedBuilding);
    if (it != buildings.end()) {
        buildings.erase(it);
        
    } else {
        std::cout << "Building bernama" << deletedBuilding.getNama() << " tidak ditemukan." << std::endl;
    }
}
void Store::deletePlant(const Plant deletedPlant)
{
    auto it = std::find(plants.begin(), plants.end(), deletedPlant);
    if (it != plants.end()) {
        plants.erase(it);
        
    } else {
        std::cout << "Plant bernama" << deletedPlant.getname() << " tidak ditemukan." << std::endl;
    }
}
void Store::deleteAnimal(const Animal deletedAnimal)
{
    auto it = std::find(animals.begin(), animals.end(), deletedAnimal);
    if (it != animals.end()) {
        animals.erase(it);
        
    } else {
        std::cout << "Animal bernama" << deletedAnimal.getname() << " tidak ditemukan." << std::endl;
    }
}
void Store::deleteProduct(const Product deletedProduct)
{
    auto it = std::find(products.begin(), products.end(), deletedProduct);
    if (it !=products.end()) {
        products.erase(it);
        
    } else {
        std::cout << "Product bernama" << deletedProduct.getname() << " tidak ditemukan." << std::endl;
    }
}

void Store::display(){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    map<string, int> countMap;

   
    for (const auto& building : buildings) {
        countMap[building.getNama()]++;
    }

    for (const auto& plant : plants) {
        countMap[plant.getname()]++;
    }

    for (const auto& animal : animals) {
        countMap[animal.getname()]++;
    }

    for (const auto& product : products) {
        countMap[product.getname()]++;
    }

    int count = 1;
    for (const auto& pair : countMap) {
        string kode = pair.first;
        int qty = pair.second;

        // Menampilkan harga berdasarkan kode barang
        int price = -1;
        for (const auto& building : buildings) {
            if (building.getNama() == kode) {
                price = building.getHarga();
                break;
            }
        }
        for (const auto& plant : plants) {
            if (plant.getname() == kode) {
                price = plant.getprice();
                break;
            }
        }
        for (const auto& animal : animals) {
            if (animal.getname() == kode) {
                price = animal.getprice();
                break;
            }
        }
        for (const auto& product : products) {
            if (product.getname() == kode) {
                price = product.getprice();
                break;
            }
        }

        cout << count << ". " << kode << " - " << price << " (" << qty << ")" << endl;
        count++;
    }
    
}


