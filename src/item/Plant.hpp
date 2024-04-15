#ifndef PLANT_HPP
#define PLANT_HPP

#include "Item.hpp"
#include "Product.hpp"
#include "../Configuration/PlantConfig.hpp"
class Plant : public Item {
    public:
        Plant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        Plant(const Plant&);
        ~Plant();
        virtual string getclassname();
        std::string gettype() const;
        int getdurationtoharvest() const;
        string getlocation() const;
        int getumur() const;
        void setumur(int n const);
        bool operator==(const Plant& other) const;
        Plant& operator=(const Plant& other);
        virtual Product* gethasilpanen();
        pair<char, int> getColumnAndRowIndex(const std::string& location) const;

    protected:
        string type;
        int durationToHarvest;
        int umur;
        string location;
};


#endif