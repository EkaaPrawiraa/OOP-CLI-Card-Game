#include "Role/Farmer.hpp"
#include "Store/Store.hpp"
#include "Storage/Storage.hpp"
#include "item/Animal.hpp"
#include "item/Plant.hpp"
#include "item/Product.hpp"
#include "item/Building.hpp"
#include <iostream>
#include <vector>

int main() {
    // Membuat objek Store
    std::vector<Plant> plants;
    std::vector<Animal> animals;
    std::vector<Building> buildings;
    std::vector<Product> products;

    Store<Building> store(buildings, plants, animals, products);

    // Membuat objek Farmer
    Farmer farmer("John", 1000, 70.5, 8, 8, 6, 6); // misalnya 8x8 untuk penyimpanan dan peternakan

    // Tes fungsi menjual
    std::cout << "===== Test Menjual =====" << std::endl;
    farmer.menjual<Building>(store); // Menggunakan tipe Building sebagai contoh
    std::cout << std::endl;

    // Tes fungsi membeli
    std::cout << "===== Test Membeli =====" << std::endl;
    farmer.membeli<Building>(store); // Menggunakan tipe Building sebagai contoh
    std::cout << std::endl;

    return 0;
}
