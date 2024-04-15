#include "Configuration/MiscConfig.hpp"
#include <iostream>

MiscConfig::MiscConfig() : winningMoney(0), winningWeight(0), storageRows(0), storageCols(0), landRows(0), landCols(0), farmRows(0), farmCols(0) {}

MiscConfig::MiscConfig(int winningMoney, int winningWeight, int storageRows, int storageCols, int landRows, int landCols, int farmRows, int farmCols)
    : winningMoney(winningMoney), winningWeight(winningWeight), storageRows(storageRows), storageCols(storageCols), landRows(landRows), landCols(landCols), farmRows(farmRows), farmCols(farmCols)
{
}

MiscConfig::~MiscConfig()
{
    // std::cout << "MiscConfig dihapus" << std::endl;
}

MiscConfig &MiscConfig::operator=(const MiscConfig &original)
{
    winningMoney = original.winningMoney;
    winningWeight = original.winningWeight;
    storageRows = original.storageRows;
    storageCols = original.storageCols;
    landRows = original.landRows;
    landCols = original.landCols;
    farmRows = original.farmRows;
    farmCols = original.farmCols;
    return *this;
}

void MiscConfig::display() const
{
    std::cout << "Winning Money: " << winningMoney << std::endl;
    std::cout << "Winning Weight: " << winningWeight << std::endl;
    std::cout << "Storage Size: " << storageRows << " x " << storageCols << std::endl;
    std::cout << "Land Size: " << landRows << " x " << landCols << std::endl;
    std::cout << "Farm Size: " << farmRows << " x " << farmCols << std::endl;
}

int MiscConfig::getWinningMoney() const
{
    return winningMoney;
}

int MiscConfig::getWinningWeight() const
{
    return winningWeight;
}

int MiscConfig::getStorageRows() const
{
    return storageRows;
}

int MiscConfig::getStorageCols() const
{
    return storageCols;
}

int MiscConfig::getLandRows() const
{
    return landRows;
}

int MiscConfig::getLandCols() const
{
    return landCols;
}

int MiscConfig::getFarmRows() const
{
    return farmRows;
}

int MiscConfig::getFarmCols() const
{
    return farmCols;
}