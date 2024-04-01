#include "Configuration\MiscConfig.hpp"
#include <iostream>

MiscConfig::MiscConfig(int winningMoney, int winningWeight, int storageRows, int storageCols, int landRows, int landCols, int farmRows, int farmCols)
    : winningMoney(winningMoney), winningWeight(winningWeight), storageRows(storageRows), storageCols(storageCols), landRows(landRows), landCols(landCols), farmRows(farmRows), farmCols(farmCols) {}

void MiscConfig::display() const
{
    std::cout << "Winning Money: " << winningMoney << std::endl;
    std::cout << "Winning Weight: " << winningWeight << std::endl;
    std::cout << "Storage Size: " << storageRows << " x " << storageCols << std::endl;
    std::cout << "Land Size: " << landRows << " x " << landCols << std::endl;
    std::cout << "Farm Size: " << farmRows << " x " << farmCols << std::endl;
}