#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>
using namespace std;
class Plant {
    public:
        Plant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        Plant(const Plant&);
        ~Plant();
        void display() const;
        string getname() const;
        std::string gettype();
        int getdurationtoharvest();
        int getprice();
        string getlocation() const;
        int getumur() const;
        int getprice() const;

    protected:
        string kodeHuruf;
        string name;
        string type;
        int durationToHarvest;
        int price;
        int umur;
        string location;
};

class MaterialPlant : public Plant {
    public:
        MaterialPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        MaterialPlant(const Plant&);
        ~MaterialPlant();
        int gethasilpanen();
    private:
        int hasilpanen;

};

class FruitPlant : public Plant {
    public:
        FruitPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        FruitPlant(const Plant&);
        ~FruitPlant();
        int gethasilpanen();
    private:
        int hasilpanen;

};

#endif