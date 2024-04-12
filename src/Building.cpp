#include "Building/Building.hpp"


string Building::getNama() const {
    return nama;
}


string Building::getKode() const {
    return kode;
}


int Building::getHarga() const {
    return harga;
}


void Building::setNama(string newNama) {
    nama = newNama;
}


void Building::setKode(string newKode) {
    kode = newKode;
}


void Building::setHarga(int newHarga) {
    harga = newHarga;
}


bool Building::operator==(const Building& other) const {
    return (this->nama == other.nama) &&
           (this->kode == other.kode) &&
           (this->harga == other.harga);
}


Building& Building::operator=(const Building& other) {
    if (this != &other) { // Check for self-assignment
        this->nama = other.nama;
        this->kode = other.kode;
        this->harga = other.harga;
    }
    return *this;
}
#include "item/Building.hpp"

// Buiilding class implementation
Material::Material(const std::string &name, int quantity)
    : name(name), quantity(quantity) {}

Building::Building(const std::string &kodeHuruf, const std::string &name, int price, const std::vector<Material> &materials)
    : Item(kodeHuruf, name, price), materials(materials) {}

Building::Building(const Building& other)
    : Item(other), materials(other.materials){}

Building::~Building() {}

std::vector<Material> Building::getmaterials(){
    return materials;
}
