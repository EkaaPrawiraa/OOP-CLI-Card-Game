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
