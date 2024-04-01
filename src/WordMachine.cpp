#include "Utility\WordMachine.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

WordMachine::WordMachine(const std::string &filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        std::cerr << "Gagal membuka file." << std::endl;
    }
}

WordMachine::~WordMachine()
{
    if (file.is_open())
    {
        file.close();
    }
}

std::vector<Plant> WordMachine::readPlants()
{
    std::vector<Plant> plants;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int id, durationToHarvest, price;
        std::string kodeHuruf, name, type;

        if (!(iss >> id >> kodeHuruf >> name >> type >> durationToHarvest >> price))
        {
            std::cerr << "Format file tidak sesuai." << std::endl;
            continue;
        }

        plants.emplace_back(id, kodeHuruf, name, type, durationToHarvest, price);
    }

    return plants;
}
std::vector<Animal> WordMachine::readAnimals()
{
    std::vector<Animal> animals;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int id, weightToHarvest, price;
        std::string kodeHuruf, name, type;

        if (!(iss >> id >> kodeHuruf >> name >> type >> weightToHarvest >> price))
        {
            std::cerr << "Format file tidak sesuai." << std::endl;
            continue;
        }

        animals.emplace_back(id, kodeHuruf, name, type, weightToHarvest, price);
    }

    return animals;
}
std::vector<Product> WordMachine::readProducts()
{
    std::vector<Product> products;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int id, addedWeight, price;
        std::string kodeHuruf, name, type, origin;

        if (!(iss >> id >> kodeHuruf >> name >> type >> origin >> addedWeight >> price))
        {
            std::cerr << "Format file tidak sesuai." << std::endl;
            continue;
        }

        products.emplace_back(id, kodeHuruf, name, type, origin, addedWeight, price);
    }

    return products;
}
MiscConfig WordMachine::readConfig()
{
    int winningMoney, winningWeight, storageRows, storageCols, landRows, landCols, farmRows, farmCols;

    if (!(file >> winningMoney >> winningWeight >> storageRows >> storageCols >> landRows >> landCols >> farmRows >> farmCols))
    {
        std::cerr << "Format file tidak sesuai." << std::endl;
        return MiscConfig(0, 0, 0, 0, 0, 0, 0, 0);
    }

    return MiscConfig(winningMoney, winningWeight, storageRows, storageCols, landRows, landCols, farmRows, farmCols);
}
std::vector<BuildingRecipe> WordMachine::readRecipes()
{
    std::vector<BuildingRecipe> recipes;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int id, price;
        std::string kodeHuruf, name, materialName;
        std::vector<Material> materials;

        if (!(iss >> id >> kodeHuruf >> name >> price))
        {
            std::cerr << "Format file tidak sesuai." << std::endl;
            continue;
        }

        while (iss >> materialName)
        {
            int quantity;
            if (!(iss >> quantity))
            {
                std::cerr << "Format file tidak sesuai." << std::endl;
                break;
            }
            materials.push_back(Material(materialName, quantity));
        }

        recipes.emplace_back(id, kodeHuruf, name, price, materials);
    }

    return recipes;
}