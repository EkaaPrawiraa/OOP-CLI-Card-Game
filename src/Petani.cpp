#include "Role/Petani.hpp"
#include <iostream>
#include <set>
#include "Storage/Storage.hpp"

Petani::Petani(string username, float weight, int uang, int storrows, int storcols, int ladrows, int ladcols)
    : Role(username, weight, uang, storrows, storcols), Ladang(ladrows, ladcols) {}

// Destructor implementation
Petani::~Petani() {}

// Virtual function implementations
void Petani::next() {}
void Petani::membeli() {}
void Petani::menjual() {}

int Petani::calculate_tax()
{
    // Implementation of tax calculation goes here
    return 0; // Placeholder return value
}

void Petani::setLadang(int row, char col, Plant *p)
{
    Ladang.setValue(row, col, p);
}

string Petani::getRoleType()
{
    return "Petani";
}

// Non-virtual function implementations
void Petani::CetakLadang()
{
    Ladang.display("Ladang");
    std::cout << "\n\n";
    // Penulisan semua kodehutuf yang ada di matrix, jika ada kode yang sama di dua tempat atay lebih, tuliskan hanya satu kode saja
    std::set<std::string> uniqueCodes;
    std::string code;
    std::string name;
    for (const auto &row : invent.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            code = cell.second->getKode();
            name = cell.second->getname();
            if (code != "   ")
            {
                if (uniqueCodes.find(code) == uniqueCodes.end())
                {
                    std::cout << "- " << code << ": " << name << std::endl; // Cetak kode tanaman
                    uniqueCodes.insert(code);                               // Tambahkan kode tanaman ke set
                }
            }
        }
    }
}
void Petani::Tanam()
{
    // Tunggu Mekanisme Penyimpanan, butuh cetak penyimpanan sama info jenis item
    //  std::cout << "Pilih petak tanah yang akan ditanami" << std::endl;
    //  CetakLadang();
    //  std::cout << "\n\n";

    // std::string lokasi;
    // std::cout << "Pilih Petak: ";
    // std::cin >> lokasi;

    // while(std::get<0>(P.get(lokasi[0], std::stoi(lokasi.substr(1)))) != "   "){
    //     std::cout << "Pastikan Petak Kosong" << std::endl;
    //     std::cout << "Pilih Petak: ";
    //     std::cin >> lokasi;
    // }

    // // P.set()
    // std::cout << "Cangkul, cangkul, cangkul yang dalam~!" << std::endl;
    // std::cout << "Orange tree berhasil ditanam!" << endl;
}
void Petani::Memanen()
{
    // this->CetakLadang();
    // std::cout << "\n\n";
    // std::cout << "Pilih tanaman siap panen yang kamu miliki\n";

    // std::vector<std::pair<std::string, int>> list = P.getCodeCounts();
    // for(int i = 0; i <list.size();i++){
    //     std::cout << "  " << i+1 << ". " << list.at(i).first << " (" << list.at(i).second << " Petak Siap Dipanen)" << std::endl;
    // }

    // int no, petak;
    // std::cout << "Nomor tanaman yang ingin dipanen:";
    // std::cin >> no;

    // while(no > list.size() || no <= 0){
    //     std::cout << "Masukkan Nomor yang Valid!\n";
    //     std::cout << "Nomor tanaman yang ingin dipanen:";
    //     std::cin >> no;
    // }

    // std::cout << "Berapa petak yang ingin dipanen:";
    // std::cin >> petak;

    // while(petak > list.at(no-1).second || petak <= 0){
    //     std::cout << "Masukkan Jumlah Petak yang Valid!\n";
    //     std::cout << "Berapa petak yang ingin dipanen:";
    //     std::cin >> petak;
    // }

    // if(petak+P.CountElement() > P.getSize()){
    //     //Throw Exception
    //     std::cout << "Jumlah Penyimpanan Tidak Cukup!" << std::endl;
    // }
    // else{
    //     std::cout << "Pilih petak yang ingin dipanen:" << std::endl;
    //     std::string lokasi, kode;
    //     std::set<std::string> locs;
    //     pair<char, int> index;
    //     for(int i = 0; i < petak;i++){
    //         std::cout << "Petak ke-" << i+1 << ": ";
    //         std::cin >> lokasi;

    //         kode = std::get<0>(P.get(lokasi[0], std::stoi(lokasi.substr(1))));
    //         while(kode != list.at(no-1).first){
    //             std::cout << "Masukkan Letak Petak yang Valid!\n";
    //             std::cout << "Petak ke-" << i+1 << ": ";
    //             std::cin >> lokasi;
    //         }

    //         P.del(lokasi[0], lokasi[2] - '0');
    //         plant.erase(std::remove_if(plant.begin(), plant.end(), [&](const Plant& plant) {
    //         return plant.getlocation() == lokasi;
    //         }), plant.end());
    //         locs.insert(lokasi);
    //     }

    //     std::cout << petak <<" petak tanaman " << list.at(no-1).first << " pada petak ";
    //     std::set<std::string>::iterator it = locs.begin();

    //     while (it != locs.end()) {
    //         if (std::next(it) == locs.end()) {
    //             std::cout << *it;
    //         } else {
    //             std::cout << *it << ", ";
    //         }
    //         ++it;
    //     }
    //     std::cout << " telah dipanen!" << std::endl;
    // }
}
