#include "Role\Farmer.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
Farmer::Farmer(string username,int gulden,float weight,inventory invent):Role( username, gulden,weight,invent){
}
Farmer::~Farmer(){}

void Farmer::setMatrix(Matrix P, int row, int col){
    F = Matrix(row,col);
    for(int i =0; i < Animals.size(); i++){
        pair<char, int> index = Animals.at(i).getColumnAndRowIndex(Animals.at(i).getlocation());
        F.set(index.first, index.second, Animals.at(i).getlocation());
    }
}
void Farmer::cetakPeternakan(int baris,int kolom){
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

void Farmer::ternak(int baris, int kolom)
{
    // Jika tidak ada hewan di penyimpanan, perintah tidak dapat dilakukan.
    // Jika kandang penuh, perintah tidak dapat dilakukan.
    cout<<"Pilih hewan dari penyimpanan"<<endl;
    Farmer::cetak_penyimpanan(baris,kolom);
    string slot;
    string lokasi;
    string hewanTerpilih;
    // ambill dari penyimpanan
    cout << "Slot: ";
    cin >>slot;
    // check if valid
    // nunggu inventory
    cout<<"Pilih petak tanah yang akan ditinggali"<<endl;
    Farmer::cetakPeternakan(baris,kolom);
    cout << "Petak tanah: ";
    cin >> lokasi;
    // check if valid

    cout<<"\nDengan hati-hati, kamu meletakkan seekor"<< hewanTerpilih <<" di kandang"<<endl;
    cout<<hewanTerpilih<<" telah menjadi peliharaanmu sekarang!"<<endl;
}
void Farmer::memberiPangan(int baris, int kolom)
{
    string petak;
    string slot;
    int beratAkhir;
    string hewanTerpilih;
    cout<<"Pilih petak kandang yang akan ditinggali"<<endl;
    cetakPeternakan(baris,kolom);
    cout<<"Petak kandang: "<<endl;
    cin >>petak;
    // validasi pemilihan
    cout<<"Kamu memilih "<< hewanTerpilih <<" untuk diberi makan."<<endl;
    cout<<"Pilih pangan yang akan diberikan"<<endl;

    cetak_penyimpanan(baris, kolom);
    cout << "Slot: ";
    cin >>slot;

    // validasi tiap input
    cout<<hewanTerpilih<<" sudah diberi makan dan beratnya menjadi "<<beratAkhir<<endl;


}
void Farmer::menjual()
{

}
void Farmer::membeli(){}

int Farmer::calculate_tax(){
    int KTKP = 11;
    int KKP=0;
    int pajak;
    int netoKekayaan =0;
    // hitung neto kekayaan
    KKP=netoKekayaan-KTKP;
    // atur jika gulden kurang tapi kekaayaan banyak
    if (KKP<= 0)
    {
        pajak=0;
    }
    else if (KKP<=6)
    {
        pajak = 0.05;
    }
    else if (KKP <=25)
    {
        pajak = 0.15;
    }
    else if (KKP <=50)
    {
        pajak = 0.25;
    }
    else if (KKP <=500)
    {
        pajak = 0.30;
    }
    else
    {
        pajak = 0.35;
    }

    int bayarPajak = round(pajak * KKP) ;
    if (getGulden()-bayarPajak<0)
    {
        bayarPajak=getGulden();
        setGulden(0);
        return bayarPajak;
    }
    else
    {
        setGulden(getGulden()-bayarPajak);
        return bayarPajak;
    }

}