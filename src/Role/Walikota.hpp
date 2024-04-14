#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Configuration/BuildingRecipeConfig.hpp"
#include "Utility/WordMachine.hpp"
#include "../src/Store/Store.hpp"
#include "../item/Building.hpp"
#include "Role.hpp"
#include "Farmer.hpp"
#include "Petani.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Walikota : public Role
{
private:
    const int static jumlah;

public:
    Walikota(string username, float weight, int uang, int storrows, int storcols);
    Walikota &conditionalConstructor(string username, float weight, int uang, int storrows, int storcols);
    virtual ~Walikota();
    virtual int calculate_tax();
    bool compareTaxTuples(std::tuple<std::string, int> &a, std::tuple<std::string, int> &b);
    void pungutPajak(std::vector<Role>);
    bool nameExists(std::string, std::vector<Role>);
    void tambahPemain(std::vector<Role>, std::vector<Plant>, MiscConfig &);
    void bangunBangunan(vector<BuildingRecipeConfig>);
    string getRoleType() override;
};

#endif