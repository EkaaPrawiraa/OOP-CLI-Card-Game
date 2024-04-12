#ifndef PLANT_HPP
#define PLANT_HPP

#include "Item.hpp"
class Plant : public Item {
    public:
        Plant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        Plant(const Plant&);
        ~Plant();

        std::string gettype() const;
        int getdurationtoharvest() const;
        string getlocation() const;
        int getumur() const;
        pair<char, int> getColumnAndRowIndex(const std::string& location) const;

    private:
        string type;
        int durationToHarvest;
        int umur;
        string location;
};


#endif