#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Item.hpp"
#include <string>

class Product : public Item {
public:
    Product(const std::string &kodeHuruf, const std::string &name, const std::string &type, const std::string &origin, int added_weight, int price);
    Product(const Product&);
    ~Product();
    std::string getclassname() override;

    std::string gettipe() const;
    std::string getorigin() const;
    int getadded_weight() const;
    int getprice() const;
    std::string getlocation() const;
<<<<<<< Updated upstream
    pair<char, int> getColumnAndRowIndex(const std::string& location) const;
=======
    std::pair<char, int> getColumnAndRowIndex(const std::string& location) const;
    bool operator==(const Product& other) const;
>>>>>>> Stashed changes
    Product& operator=(const Product& other);

private:
    std::string type;
    std::string origin;
    int added_weight;
};

#endif
