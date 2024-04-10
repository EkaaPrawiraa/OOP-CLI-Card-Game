#include "Role/Role.hpp"

Role::Role(string username, float weight, int uang, Matrix invent)
{
    this->username = username;
    this->weight = weight;
    this->gulden = uang;
}
Role::~Role() {}
void Role::next()
{
}
void Role::cetak_penyimpanan(int baris, int kolom)
{
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
}
float Role::getWeight()
{
}
void Role::setGulden(int)
{
}
void Role::setWeight(float)
{
}
Matrix Role::getInventory()
{
    return invent;
}
