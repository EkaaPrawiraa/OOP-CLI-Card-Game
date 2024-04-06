#ifndef PRODUCTCONFIG_HPP
#define PRODUCTCONFIG_HPP

#include <string>

class ProductConfig
{
public:
    int id;
    std::string kodeHuruf;
    std::string name;
    std::string type;
    std::string origin;
    int addedWeight;
    int price;

    ProductConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, const std::string &origin, int addedWeight, int price);
    void display() const;
};

#endif

// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE