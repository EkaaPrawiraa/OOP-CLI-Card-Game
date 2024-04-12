#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Item.hpp"

class Product : public Item{
    public:
    Product(const string &kodeHuruf,const string &name, const string &type, const string &origin, int added_weight, int price);
    Product(const Product&);
    ~Product();
    string getclassname() override;

    std::string gettipe()  const;
    std::string getorigin()  const;
    int getadded_weight()  const;
    int getprice()  const;
    std::string getlocation() const;
    bool operator==(const Product& other) const;
    pair<char, int> getColumnAndRowIndex(const std::string& location) const;
    bool operator==(const Product& other) const;
    Product& operator=(const Product& other);

    private:
    std::string type;
    std::string origin;
    int added_weight;

};


#endif