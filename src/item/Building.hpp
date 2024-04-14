#ifndef Building_HPP
#define Building_HPP

#include "Item.hpp"
#include <vector>
#include <utility> 

class Building : public Item {
public:
    Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::pair<std::string, int> >& materials);
    Building(const Building&);
    ~Building();

    std::string getclassname() override;
    std::vector< pair<string,int> > getmaterials() const;
    bool operator==(const Building& other) const;
    Building& operator=(const Building& other);
    void setNama(string);
    void setKode(string);
    void setHarga(int);

private:
    vector< pair<string,int> > materials;
};

#endif
