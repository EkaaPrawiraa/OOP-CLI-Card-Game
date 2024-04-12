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
    int static jumlah;
    std::vector<std::tuple<std::string, int>> Bangunan;

public:
    virtual int calculate_tax();
    bool compareTuples(std::tuple<std::string, int> &a, std::tuple<std::string, int> &b);
    void pungutPajak(std::vector<Role>);
    bool nameExists(std::string, std::vector<Role>);
    void tambahPemain(std::vector<Role>, std::vector<Plant>, MiscConfig &);
    void bangunBangunan(vector<BuildingRecipeConfig>);
};

#endif