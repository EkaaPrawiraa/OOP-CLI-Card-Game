#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Item.hpp"
#include <string>
#include "../Configuration/ProductConfig.hpp"
#include <vector>

class Product : public Item {
public:
    Product(const std::string &kodeHuruf, const std::string &name, const std::string &type, const std::string &origin, int added_weight, int price);
    Product(const Product&);
    Product(const std::vector<ProductConfig>& configs, const std::string& name);
    ~Product();
    std::string getclassname();

    std::string gettipe() const;
    std::string getorigin() const;
    int getadded_weight() const;
    int getprice() const;
    std::string getlocation() const;
    std::pair<char, int> getColumnAndRowIndex(const std::string& location) const;
    bool operator==(const Product& other) const;
    Product& operator=(const Product& other);

private:
    std::string type;
    std::string origin;
    int added_weight;
};

#endif
