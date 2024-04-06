#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <string>
#include <vector>
#include "Configuration/ProductConfig.hpp"
class Product {
private:
    std::string kodeHuruf;
    std::string name;
    std::string tipe;
    std::string origin;
    int added_weight;
    int price;

public:
    Product(std::string kodehuruf, const std::vector<ProductConfig>& vec);

    std::string getkodeHuruf();
    std::string getname();
    std::string gettipe();
    std::string getorigin();
    int getadded_weight();
    int getprice();
};


#endif