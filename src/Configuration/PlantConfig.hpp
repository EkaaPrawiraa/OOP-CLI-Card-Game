#ifndef PLANTCONFIG_HPP
#define PLANTCONFIG_HPP

#include <string>

class PlantConfig
{
public:
    PlantConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int durationToHarvest, int price);
    void display() const;
    int getid();
    std::string getcode();
    std::string getname();
    std::string gettype();
    int getdurationtoharvest();
    int getprice();

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