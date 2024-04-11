// #include "..//PlantAnimal//Plant.hpp"
// #include "..//PlantAnimal//Animal.hpp"
// #include "..//Product//Product.hpp"
// #include "..//Building//Building.hpp"
#include <vector>
#include "../PlantAnimal/Plant.hpp"
#include "../PlantAnimal/Animal.hpp"
#include "../Product/Product.hpp"
#include "../Building/Building.hpp"

using namespace std;

class Store{
    private:
    vector<Building> buildings;
    vector<Plant> plants;
    vector<Animal> animals;
    vector<Product> products;
    // berisi nama barang, harga, dan kuantiti barng
    // vector < tuple<string,int,int> > items;



    public:
    Store(const vector<Plant> &plants,const vector<Animal> &animals);
    Store(const vector<Building> &buildings,const vector<Plant> &plants,const vector<Animal> &animals,const vector<Product> &products);
    ~Store();

    // add ketika ada yang menjual barang ke store
    void addBuilding(const Building addedBuilding);
    void addPlant(const Plant addedPlant);
    void addAnimal(const Animal addedAnimal);
    void addProduct(const Product addedProduct);
    // delete ketika ada yang membeli barang dari store
    void deleteBuilding(const Building);
    void deletePlant(const Plant);
    void deleteAnimal(const Animal);
    void deleteProduct(const Product);
    // set harga barang
    int getPriceBuilding(const string kode);
    int getPricePlant(const string kode);
    int getPriceAnimal(const string kode);
    int getPriceProduct(const string kode);
    int getJumlah(string kode);
    int buyItem(const string kode,const int quantity,const int usersmoney);
    int sellItem(const string kode,bool);
    void display();
};