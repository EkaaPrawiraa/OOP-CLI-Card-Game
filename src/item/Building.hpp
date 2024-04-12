#ifndef Building_HPP
#define Building_HPP

#include "Item.hpp"
#include <vector>

class Building : public Item
{
public:
    // tuple string dan int (tipe material untuk name dan quantity)
    Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::tuple<std::string, int>> &materials);
    Building(const Building &);
    ~Building();
    std::string getclassname() override;
    std::vector<std::tuple<std::string, int>> getmaterials();
    bool operator==(const Building &other) const;
    Building &operator=(const Building &other);
    string getNama() const;
    string getKode() const;
    int getHarga() const;
    void setNama(string);
    void setKode(string);
    void setHarga(int);

private:
    std::vector<std::tuple<std::string, int>> materials;
};

#endif