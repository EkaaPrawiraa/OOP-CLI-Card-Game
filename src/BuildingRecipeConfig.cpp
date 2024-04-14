// #include "Configuration/BuildingRecipeConfig.hpp"
// #include <iostream>

// BuildingRecipeConfig::BuildingRecipeConfig(int id, const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::tuple<std::string, int>> &materials)
//     : id(id), kodeHuruf(kodeHuruf), name(name), price(price), materials(materials) {}

// void BuildingRecipeConfig::display() const
// {
//     std::cout << "ID: " << id << ", "
//               << "Kode Huruf: " << kodeHuruf << ", "
//               << "Name: " << name << ", "
//               << "Price: " << price << std::endl;

//     std::cout << "Materials:" << std::endl;
//     for (const auto &material : materials)
//     {
//         std::cout << "- " << std::get<0>(material) << ": " << std::get<1>(material) << std::endl;
//     }
// }
// int BuildingRecipeConfig::getid()
// {
//     return id;
// }
// std::string BuildingRecipeConfig::getcode()
// {
//     return kodeHuruf;
// }
// std::string BuildingRecipeConfig::getname()
// {
//     return name;
// }
// int BuildingRecipeConfig::getprice()
// {
//     return price;
// }
// std::vector<std::tuple<std::string, int>> BuildingRecipeConfig::getmaterials()
// {
//     return materials;
// }
