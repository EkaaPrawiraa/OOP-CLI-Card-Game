#ifndef PLANTCONFIG_HPP
#define PLANTCONFIG_HPP

#include <string>

class PlantConfig
{
public:
    PlantConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int durationToHarvest, int price);
    void display() const;
    int getid() const;
    std::string getcode() const;
    std::string getname() const;
    std::string gettype() const;
    int getdurationtoharvest() const;
    int getprice() const;
    PlantConfig& operator=(const PlantConfig& other);

private:
    int id;
    std::string kodeHuruf;
    std::string name;
    std::string type;
    int durationToHarvest;
    int price;
};

#endif


// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE