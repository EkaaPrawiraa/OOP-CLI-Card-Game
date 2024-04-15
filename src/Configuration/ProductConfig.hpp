#ifndef PRODUCTCONFIG_HPP
#define PRODUCTCONFIG_HPP

#include <string>

class ProductConfig
{
private:
    int id;
    std::string kodeHuruf;
    std::string name;
    std::string type;
    std::string origin;
    int addedWeight;
    int price;

public:
    ProductConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, const std::string &origin, int addedWeight, int price);
    void display() const;
    std::string getcode() const;
    std::string getname() const;
    std::string gettype() const;
    std::string getorigin() const;
    int getaddedtoweight() const;
    int getprice() const;
};

#endif

// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE