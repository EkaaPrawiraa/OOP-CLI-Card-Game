#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>
class Role{
private:
    std::string username;
    int gulden;
    float weight;
    Inventory invent;

public:
    Role(string username, float weight, int uang);
    virtual ~Role();
    virtual void next();
    void cetak_penyimpanan();
    void makan();
    virtual void membeli();
    virtual void menjual();
    virtual int calculate_tax()=0;
};


#endif