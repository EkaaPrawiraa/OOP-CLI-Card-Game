#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>

class PlantConfig
{
public:
    int id;
    std::string kodeHuruf;
    std::string name;
    std::string type;
    int durationToHarvest;
    int price;

    PlantConfig(int id, const std::string &kodeHuruf, const std::string &name, const std::string &type, int durationToHarvest, int price);
    void display() const;
    int getid();
    std::string getcode();
    std::string getname();
    std::string gettype();
    int getdurationtoharvest();
    int getprice();
};

#endif


// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE