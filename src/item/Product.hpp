#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Item.hpp"

class Product : public Item{
    public:
    Product(const string &kodeHuruf,const string &name, const string &type, const string &origin, int added_weight, int price, const string &location);
    Product(const Product&);
    ~Product();
    string getclassname(){
        return "Product";
    }

    std::string gettipe()  const;
    std::string getorigin()  const;
    int getadded_weight()  const;
    int getprice()  const;
    std::string getlocation() const;
    pair<char, int> getColumnAndRowIndex(const std::string& location) const;
    bool operator==(const Product& other) const;
    Product& operator=(const Product& other);

    private:
    std::string type;
    std::string origin;
    int added_weight;
    string location;

};


#endif