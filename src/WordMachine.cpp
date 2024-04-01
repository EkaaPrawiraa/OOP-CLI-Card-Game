#include "Utility\WordMachine.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

WordMachine::WordMachine(const string &filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        throw FileException("Gagal membuka file."); // handle pake exception
    }
}

WordMachine::~WordMachine()
{
    if (file.is_open())
    {
        file.close();
    }
}

vector<Plant> WordMachine::readPlants()
{
    vector<Plant> plants;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, durationToHarvest, price;
        string kodeHuruf, name, type;

        if (!(iss >> id >> kodeHuruf >> name >> type >> durationToHarvest >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
            continue;
        }

        plants.emplace_back(id, kodeHuruf, name, type, durationToHarvest, price);
    }

    return plants;
}
vector<Animal> WordMachine::readAnimals()
{
    vector<Animal> animals;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, weightToHarvest, price;
        string kodeHuruf, name, type;

        if (!(iss >> id >> kodeHuruf >> name >> type >> weightToHarvest >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
            continue;
        }

        animals.emplace_back(id, kodeHuruf, name, type, weightToHarvest, price);
    }

    return animals;
}
vector<Product> WordMachine::readProducts()
{
    vector<Product> products;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, addedWeight, price;
        string kodeHuruf, name, type, origin;

        if (!(iss >> id >> kodeHuruf >> name >> type >> origin >> addedWeight >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
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
        throw FileException("Format file plants tidak sesuai.");
        return MiscConfig(0, 0, 0, 0, 0, 0, 0, 0);
    }

    return MiscConfig(winningMoney, winningWeight, storageRows, storageCols, landRows, landCols, farmRows, farmCols);
}
vector<BuildingRecipe> WordMachine::readRecipes()
{
    vector<BuildingRecipe> recipes;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price;
        string kodeHuruf, name, materialName;
        vector<Material> materials;

        if (!(iss >> id >> kodeHuruf >> name >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
            continue;
        }

        while (iss >> materialName)
        {
            int quantity;
            if (!(iss >> quantity))
            {
                throw FileException("Format file plants tidak sesuai.");
                break;
            }
            materials.push_back(Material(materialName, quantity));
        }

        recipes.emplace_back(id, kodeHuruf, name, price, materials);
    }

    return recipes;
}