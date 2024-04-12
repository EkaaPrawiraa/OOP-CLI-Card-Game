#ifndef Building_HPP
#define Building_HPP

#include "Item.hpp"
#include <vector>

struct Material
{
    std::string name;
    int quantity;
    Material(const std::string &name, int quantity);
};

class Building : public Item {
    public:
        Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials);
        Building(const Building&);
        ~Building();
        std::string getclassname() override;
        std::vector<Material> getmaterials();
        bool operator==(const Building& other) const;
        Building& operator=(const Building& other);
        string getNama() const;
        string getKode() const;
        int getHarga()  const;
        void setNama(string) ;
        void setKode(string);
        void setHarga(int );
        
    private:
        std::vector<Material> materials;
};


#endif