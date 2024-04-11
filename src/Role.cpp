#include "Role/Role.hpp"

Role::Role(string username, float weight, int uang, Matrix invent)
{
    this->username = username;
    this->weight = weight;
    this->gulden = uang;
    this->invent = invent;
}
Role::~Role() {}
void Role::next()
{
}
void Role::cetak_penyimpanan(int baris, int kolom)
{
    invent.display("Penyimpanan");
}
void Role::makan()
{
}
void Role::membeli()
{
}
void Role::menjual()
{
}
int Role::getGulden()
{
    return gulden;
}
float Role::getWeight()
{
    return weight;
}
void Role::setGulden(int gulden)
{
    this->gulden=gulden;
}
void Role::setWeight(float weight)
{
    this->weight=weight;
}
Matrix Role::getInventory()
{
    return invent;
}
