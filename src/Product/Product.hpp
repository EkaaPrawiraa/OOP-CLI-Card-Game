#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <string>
#include <vector>
#include "../Configuration/ProductConfig.hpp"

using namespace std;
class Product {
private:
    std::string kodeHuruf;
    std::string name;
    std::string tipe;
    std::string origin;
    int added_weight;
    int price;
    string location;

public:
    Product();
    Product(std::string kodehuruf, const std::vector<ProductConfig>& vec, std::string location);

    std::string getkodeHuruf() const;
    std::string getname()  const;
    std::string gettipe()  const;
    std::string getorigin()  const;
    int getadded_weight()  const;
    int getprice()  const;
    bool operator==(const Product& other) const;
    std::string getlocation() const;
    pair<char, int> getColumnAndRowIndex(const std::string& location) const;
};


#endif