#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Configuration/BuildingRecipeConfig.hpp"
#include "Utility/WordMachine.hpp"
#include "Role.hpp"
#include "Farmer.hpp"
#include "Petani.hpp"
#include <string>
#include <iostream>
#include <vector>

class Walikota : public Role
{
private:
    int static jumlah;
    std::vector<Material> Bangunan;

public:
    void pungutPajak(std::vector<Role>);
    void bangunBangunan(vector<BuildingRecipeConfig>);
    void tambahPemain(std::vector<Role>);
};

#endif