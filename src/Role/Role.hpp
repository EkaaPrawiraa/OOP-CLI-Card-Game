#ifndef ROLE_HPP
#define ROLE_HPP

#include <string>
#include <iostream>
#include "../Storage/Storage.hpp"
#include "../item/Item.hpp"
#include "../item/Product.hpp"
#include "../item/Animal.hpp"
#include "../item/Building.hpp"
#include "../item/MaterialPlant.hpp"
#include "../item/FruitPlant.hpp"
#include "../item/Karnivora.hpp"
#include "../item/Omnivora.hpp"
#include "../item/Herbivora.hpp"
// #include "../Utility/Exception.hpp"
using namespace std;

class Role
{
private:
protected:
    std::string username;
    int gulden;
    float weight;
    Matrix<Item *> invent;

public:
    Role(string username, float weight, int uang, int storrows, int storcols);
    virtual ~Role();
    virtual void next() = 0; // virtual pure method
    virtual void membeli() = 0; // virtual pure method
    virtual void menjual() = 0; // virtual pure method
    virtual void cetakPeternakan() = 0; // virtual pure method
    virtual void cetakLadang() = 0; // virtual pure method
    virtual void Tanam() = 0; // virtual pure method
    virtual void Memanen() = 0; // virtual pure method
    virtual void bangunBangunan(std::vector<BuildingRecipeConfig>) = 0; // virtual pure method
    virtual void pungutPajak(std::vector<Role *>) = 0; // virtual pure method
    virtual void memberiPangan() = 0; // virtual pure method
    virtual void updateUmurTumbuhan() = 0; // virtual pure method
    virtual void tambahPemain(std::vector<Role *> &) = 0; // virtual pure method
    virtual int calculate_tax() = 0;
    std::string getUsername() const;
    int getGulden();
    float getWeight();
    void setGulden(int gulden);
    void setWeight(float weight);
    virtual string getRoleType();
    Matrix<Item*>& getInventory();

     void cetak_penyimpanan();
     void makan();
};

#endif // NAMA_FILE_HPP