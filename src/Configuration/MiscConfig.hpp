#ifndef MISCCONFIG_HPP
#define MISCCONFIG_HPP

class MiscConfig
{
private:
    int winningMoney;
    int winningWeight;
    int storageRows;
    int storageCols;
    int landRows;
    int landCols;
    int farmRows;
    int farmCols;

public:
    MiscConfig();
    MiscConfig(int winningMoney, int winningWeight, int storageRows, int storageCols, int landRows, int landCols, int farmRows, int farmCols);
    ~MiscConfig();
    MiscConfig &operator=(const MiscConfig &);
    void display() const;
    int getWinningMoney() const;
    int getWinningWeight() const;
    int getStorageRows() const;
    int getStorageCols() const;
    int getLandRows() const;
    int getLandCols() const;
    int getFarmRows() const;
    int getFarmCols() const;
};

#endif

// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE