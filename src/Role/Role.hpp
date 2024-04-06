#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>
using namespace std;
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
    void cetak_penyimpanan(int baris, int kolom);
    void makan();
    virtual void membeli();
    virtual void menjual();
    virtual int calculate_tax()=0;
    int getGulden();
    float getWeight();
    void setGulden(int );
    void setWeight(float);
};


#endif