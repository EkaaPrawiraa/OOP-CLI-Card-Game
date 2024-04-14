#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "../Configuration/BuildingRecipeConfig.hpp"
#include "../Utility/WordMachine.hpp"
// #include "../Store/Store.hpp"
#include "../item/Building.hpp"
#include "Role.hpp"
// #include "Farmer.hpp"
// #include "Petani.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

class Walikota : public Role
{
private:
    int static jumlah;

public:
    Walikota(string username, float weight, int uang, int storrows, int storcols);
    friend Walikota conditionalConstructor(string username, float weight, int uang, int storrows, int storcols);
    static bool compareTaxTuples(std::tuple<Role *, int> a, std::tuple<Role *, int> b);
    virtual ~Walikota();
    virtual int calculate_tax();
    void pungutPajak(std::vector<Role *>);
    bool nameExists(std::string, std::vector<Role *>);
    static bool sortUsername(Role *a, Role *b);
    void tambahPemain(std::vector<Role *>);
    void bangunBangunan(vector<BuildingRecipeConfig>);
    void next() override;
    string getRoleType() override;
};

Walikota conditionalConstructor(string username, float weight, int uang, int storrows, int storcols);

#endif