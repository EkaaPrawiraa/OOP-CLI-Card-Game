#include "Store/Store.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// buat startgame karna plant dan animal tak hingga jumlahnya
Store::Store(const vector<PlantConfig> &plantConfigs,const vector<AnimalConfig> &animalConfigs ){
    
    animals.clear(); 
    for (const auto& config : animalConfigs)
    {
        
        Animal animal(config.getcode(), config.getname(), config.gettype(), config.getweighttoharvest(), config.getprice(),0, ""); // 0 or another value depending on your needs
        animals.push_back(animal);
    }
   
    plants.clear(); 
    for (const auto& config : plantConfigs)
    {
        Plant plant(config.getcode(), config.getname(), config.gettype(), config.getdurationtoharvest(), config.getprice(), 0,"");
        plants.push_back(plant);
    }
    
}

// buat dari state txt
Store::Store(const vector<Building> &buildings,const vector<Plant> &plants,const vector<Animal> &animals,const vector<Product> &products)
{
    this->buildings=buildings;
    this->plants=plants;
    this->animals=animals;
    this->products=products;
}

Store::~Store(){
    this->buildings.clear();
    this->plants.clear();
    this->animals.clear();
    this->products.clear();
}

void Store::addBuilding(const Building& addedBuilding)
{
    buildings.push_back(addedBuilding);
}
void Store::addPlant(const Plant& addedPlant)
{
    plants.push_back(addedPlant);
}
void Store::addAnimal(const Animal& addedAnimal)
{
    animals.push_back(addedAnimal);
}
void Store::addProduct(const Product& addedProduct)
{
    products.push_back(addedProduct);
}
void Store::deleteBuilding(const Building deletedBuilding)
{
    auto it = std::find(buildings.begin(), buildings.end(), deletedBuilding);
    if (it != buildings.end()) {
        buildings.erase(it);
        
    } else {
        std::cout << "Building bernama" << deletedBuilding.getname() << " tidak ditemukan." << std::endl;
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
        countMap[building.getname()]++;
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
        string code;
        int price = -1;
        for (const auto& building : buildings) {
            if (building.getname() == kode) {
                code = building.getKode();
                price = building.getprice();
                break;
            }
        }
        for (const auto& plant : plants) {
            if (plant.getname() == kode) {
                code = plant.getKode();
                price = plant.getprice();
                break;
            }
        }
        for (const auto& animal : animals) {
            if (animal.getname() == kode) {
                code = animal.getKode();
                price = animal.getprice();
                break;
            }
        }
        for (const auto& product : products) {
            if (product.getname() == kode) {
                code = product.getKode();
                price = product.getprice();
                break;
            }
        }

        cout << count << ". " << kode <<" ("<<code<<") "  <<" - " << price;
        
        
        if (qty > 1) {
            cout << " (" << qty << ")";
        }
        
        cout << endl;
        count++;
    }
}


int Store::getPriceBuilding(const string kode) {
    for (const auto& building : buildings) {
        if (building.getKode() == kode) {
            return building.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::getPricePlant(const string kode) {
    for (const auto& plant : plants) {
        if (plant.getKode() == kode) {
            return plant.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::getPriceAnimal(const string kode) {
    for (const auto& animal : animals) {
        if (animal.getKode() == kode) {
            return animal.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::getPriceProduct(const string kode) {
    for (const auto& product : products) {
        if (product.getKode() == kode) {
            return product.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

// template <typename T>
std::pair<int,Item*> Store::buyItem(const string  kode, int quantity,int usersmoney,string role)
{
    Item* item  = new Item(animals.front());
    bool quantityEnough = true;
    int totalHarga =0;
    if (quantity <= 0 || usersmoney <= 0) {
        cout << "Quantity dan uang harus lebih dari 0." << endl;
        return make_pair(0, item);
    }
    for (Plant& plant : plants){
        if (plant.getKode() == kode)
        {
            totalHarga = plant.getprice()*quantity;
            if (totalHarga>usersmoney)
            {
                cout<<"Uang Anda kurang, gulden yang dibutuhkan : "<<totalHarga<<endl;
                return make_pair(0, item);
            }
            if (totalHarga>0)
            {
                return make_pair(totalHarga, new Plant(plant.getKode(), plant.getname(), plant.gettype(), plant.getdurationtoharvest(), plant.getprice(), 0," "));
            }
            
        }
    }
    for (Animal& animal : animals) {
        if (animal.getKode() == kode)
        {
            totalHarga = animal.getprice()*quantity;
            if (totalHarga>usersmoney)
            {
                cout<<"Uang Anda kurang, gulden yang dibutuhkan : "<<totalHarga<<endl;
                return make_pair(0, item);
            }
            if (totalHarga>0)
            {
                return make_pair(totalHarga, new Animal(animal.getKode(), animal.getname(), animal.gettype(), animal.getweighttoharvest(), animal.getprice(), animal.getberat(), ""));
            }
            
            
        }
    }
    for (Product& product : products)
    {
        if (product.getKode() == kode)
        {
            if (getJumlah(product.getKode())<quantity)
            {
                quantityEnough = false;
                
            }
            if (!quantityEnough){
                // UNTUK QUANTITY ASKED MODE THAN THE STORE HAS
                cout<<"Quantity barang yang ingin dibeli tidak cukup."<<endl;
                return make_pair(0, item);
            }
            totalHarga = product.getprice()*quantity;
            if (totalHarga>usersmoney)
            {
                cout<<"Uang Anda kurang, gulden yang dibutuhkan : "<<totalHarga<<endl;
                return make_pair(0, item);
            }
            
            
            if (totalHarga>0)
            {   
                Product* p = new Product(product.getKode(), product.getname(), product.gettipe(), product.getorigin(), product.getadded_weight(), product.getprice());
                for (int i =0;i<quantity;i++)
                {
                    deleteProduct(product);
                }

                
                return make_pair(totalHarga, p);
            }
            
        }
    }
    for (Building& building : buildings)
    {
        if (building.getKode() == kode)
        {
            if (role=="Walikota")
            {
                cout<<"Walikota tidak dapat membeli bangunan!"<<endl;
                return make_pair(0, item);
            }
            if (getJumlah(building.getKode())<quantity)
            {
                quantityEnough = false;
                
            }
            if (!quantityEnough){
                // UNTUK QUANTITY ASKED MODE THAN THE STORE HAS
                cout<<"Quantity barang yang ingin dibeli tidak cukup."<<endl;
                return make_pair(0, item);
            }
            totalHarga = building.getprice()*quantity;
            if (totalHarga>usersmoney)
            {
                cout<<"Uang Anda kurang, gulden yang dibutuhkan : "<<totalHarga<<endl;
                return make_pair(0, item);
            }
            if (totalHarga>0)
            {
                Building* p = new Building(building.getKode(), building.getname(), building.getprice(), building.getmaterials());
                for (int i =0;i<quantity;i++)
                {
                deleteBuilding(building);
                }
                return make_pair(totalHarga, p);
            }
            
            
            
        }
    }
    if (totalHarga == 0){
        // untuk kode tidak ditemukan
        // item = NULL;
        cout <<"Kode barang tidak terdapat di toko."<<endl;
        return make_pair(0, item);
    }
 return make_pair(0,item);
}

int Store::sellItem(Item* item) {
    if (Building* buildingItem = dynamic_cast<Building*>(item)) {
        // cout<<"KDKDK";
        addBuilding(*buildingItem);
    } else if (Product* productItem = dynamic_cast<Product*>(item)) {
        // cout<<"ASSS";
        addProduct(*productItem);
    }
    return item->getprice(); // Jika ada kesalahan, kembalikan 0
}

int Store::getJumlah(string kode) const{
    int jumlah = 0;
    // Periksa jumlah building
    for (const Building& building : buildings) {
        if (building.getKode() == kode) {
            jumlah++;
        }
    }
    if (jumlah>0)
    {
        return jumlah;
    }
    // Periksa jumlah plant
    for (const Plant& plant : plants) {
        if (plant.getKode() == kode) {
            jumlah++;
        }
    }
    if (jumlah>0)
    {
        return jumlah;
    }
    // Periksa jumlah animal
    for (const Animal& animal : animals) {
        if (animal.getKode() == kode) {
            jumlah++;
        }
    }
    if (jumlah>0)
    {
        return jumlah;
    }

    // Periksa jumlah product
    for (const Product& product : products) {
        if (product.getKode() == kode) {
            jumlah++;
        }
    }

    return jumlah;
}

vector<Building> Store::getbuilding() const{
    return buildings;
}
vector<Product> Store::getproduct() const{
    return products;
}

