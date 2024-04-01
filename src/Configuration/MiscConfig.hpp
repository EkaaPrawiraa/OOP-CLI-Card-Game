#ifndef MISCCONFIG_HPP
#define MISCCONFIG_HPP

class MiscConfig
{
public:
    int winningMoney;
    int winningWeight;
    int storageRows;
    int storageCols;
    int landRows;
    int landCols;
    int farmRows;
    int farmCols;

    MiscConfig(int winningMoney, int winningWeight, int storageRows, int storageCols, int landRows, int landCols, int farmRows, int farmCols);
    void display() const;
};

#endif 

// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE