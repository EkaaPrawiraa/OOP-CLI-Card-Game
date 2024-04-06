#include "Role\Farmer.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
Farmer::Farmer(string username,int gulden,float weight,inventory invent):Role( username, gulden,weight,invent){
}
Farmer::~Farmer(){}

void Farmer::cetakPeternakan(){
    std::cout << "================[ Peternakan ]===================\n";
    // std::cout << "   A     B     C     D     E     F     G\n";
    // std::cout << " +-----+-----+-----+-----+-----+-----+-----+\n";

    
    // std::vector<std::vector<std::string>> ladang(8, std::vector<std::string>(7, ""));

    // for (const auto& plant : Plants) {
    //     int row = plant.getlocation()[0] - '0' - 1;
    //     char col = plant.getlocation()[1];
    //     int colIndex = col - 'A';

    //     ladang[row][colIndex] = plant.getKode();
    // }

    // for (int i = 0; i < ladang.size(); ++i) {
    //     std::cout << "0" << i + 1 << " | ";
    //     for (int j = 0; j < ladang[i].size(); ++j) {
    //         std::cout << ladang[i][j] << " | ";
    //     }
    //     std::cout << "\n +-----+-----+-----+-----+-----+-----+-----+\n";
    // }

}

void Farmer::ternak()
{
    Farmer::cetakPeternakan();
    string slot;
    string lokasi;
    cout << "Slot: ";
    cin >>slot;
    // check if valid
    // nunggu inventory
    cout << "Petak tanah: ";
    cin >> lokasi;
    // check if valid

    cout<<"\nCangkul, cangkul, cangkul yang dalam~!"<<endl;
    cout<<"Orange tree berhasil ditanam!"<<endl;
}
