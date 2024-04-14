#include "item/Building.hpp"

<<<<<<< Updated upstream
string Building::getNama() const
{
    return nama;
}

string Building::getKode() const
{
    return kode;
}

int Building::getHarga() const
{
    return harga;
}

void Building::setNama(string newNama)
{
    nama = newNama;
}

void Building::setKode(string newKode)
{
    kode = newKode;
}

void Building::setHarga(int newHarga)
{
    harga = newHarga;
}

bool Building::operator==(const Building &other) const
{
    return (this->nama == other.nama) &&
           (this->kode == other.kode) &&
           (this->harga == other.harga);
}

Building &Building::operator=(const Building &other)
{
    if (this != &other)
    { // Check for self-assignment
        this->nama = other.nama;
        this->kode = other.kode;
        this->harga = other.harga;
=======
Building::Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::pair<std::string, int> >& materials)
    : Item(kodeHuruf, name, price), materials(materials) {}

Building::Building(const Building& other)
    : Item(other), materials(other.materials) {}

Building::~Building() {}

vector< pair<string, int> > Building::getmaterials() const {
    return materials;
}

std::string Building::getclassname() {
    return "Building";
}

bool Building::operator==(const Building& other) const {
    return (this->name == other.name) &&
           (this->kodeHuruf == other.kodeHuruf) &&
           (this->price == other.price) &&
           (this->materials == other.materials); // perbandingan material
}

Building& Building::operator=(const Building& other) {
    if (this != &other) {
        this->name = other.name;
        this->kodeHuruf = other.kodeHuruf;
        this->price = other.price;
        this->materials = other.materials; // penugasan material
>>>>>>> Stashed changes
    }
    return *this;
}

<<<<<<< Updated upstream
// Buiilding class implementation
Building::Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<std::tuple<std::string, int>> &materials)
    : Item(kodeHuruf, name, price), materials(materials) {}

Building::Building(const Building &other)
    : Item(other), materials(other.materials) {}

Building::~Building() {}

std::vector<std::tuple<std::string, int>> Building::getmaterials()
{
    return materials;
}
string Building::getclassname()
{
    return "Building";
}
=======
>>>>>>> Stashed changes
