#include "Role/Farmer.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
Farmer::Farmer(string username,int gulden,float weight,Matrix invent):Role( username, gulden,weight,invent){
}
Farmer::~Farmer(){}

void Farmer::setMatrix(){
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
void Farmer::menjual(Store Toko)
{
    // validasi tidak bisa menjual bangunan jika bukan walikota
    if (invent.CountElement()==0)
    {
        cout<<"Penyimpanan Anda kosong tidak bisa melakukan penjualan"<<endl;
    }
    else{
        invent.display();
        cout<<"Silahkan pilih petak yang ingin Anda jual!"<<endl;
        cout <<"Petak : ";
        string slotInput;
        getline(std::cin,slotInput);

        // Membuat stringstream dari input untuk memproses token
        std::stringstream ss(slotInput);
        std::string token;
        std::vector<std::string> tokens;

        // Memproses token dari stringstream
        while (std::getline(ss, token, ',')) {
            // Menghapus spasi tambahan dari token
            token.erase(0, token.find_first_not_of(" "));
            token.erase(token.find_last_not_of(" ") + 1);

            tokens.push_back(token);
        }
        int totalPrice=0;
        // validasi apkah petak ada isinya

        // check barang yang dijual apa biar tau manggil fungsi delete yang mana


        cout<<"Barang Anda berhasil dijual! Uang Anda bertambah "<<totalPrice<<" gulden!"<<endl;

    }
}
void Farmer::membeli(Store Toko){
    if (invent.isFull())
    {
        cout <<"Penyimpanan Anda Penuh tidak bisa melakukan pembelian"<<endl;
    }
    else{
        
        Toko.display();
        cout<<"\n\n";
        cout <<"Uang Anda : "<<this->gulden<<endl;
        cout<<"Slot penyimpanan tersedia: "<<invent.getSize()-invent.CountElement()<<endl;
        string boughtItem;
        cout<<"Kode barang yang ingin dibeli : ";
        cin>>boughtItem;
        int quantity = 0;
        cout<<"Kuantitas : ";
        cin >>quantity;
        while(invent.CountElement()+quantity>invent.getSize())
        {
            cout<<"Penyimpanan anda tidak cukup!"<<endl;
            cout<<"Sisa penyimpanan : "<<invent.getSize()-invent.CountElement()<<endl;
            cout<<"Kuantitas : ";
            cin >>quantity;
        }
        
        int totalpaid = Toko.buyItem(boughtItem,quantity,);
        if (totalpaid>0)
        {
            this->gulden -= totalpaid;
            cout<<endl;
            cout <<"Selamat Anda berhasil membeli "<<quantity<<" "<<boughtItem<<". Uang Anda tersisa "<<this->gulden<<" gulden."<<endl;
            cout<<endl;
            cout<<"Pilih slot untuk menyimpan barang yang Anda beli!"<<endl;
            // belum tau cetak penyimpanan
            invent.display();
            // atur cetak penyimpanan
            cout<<endl;

            cout<<"Petak slot: ";
            string slotInput;
            getline(std::cin,slotInput);

            // Membuat stringstream dari input untuk memproses token
            std::stringstream ss(slotInput);
            std::string token;
            std::vector<std::string> tokens;

            // Memproses token dari stringstream
            while (std::getline(ss, token, ',')) {
                // Menghapus spasi tambahan dari token
                token.erase(0, token.find_first_not_of(" "));
                token.erase(token.find_last_not_of(" ") + 1);

                tokens.push_back(token);
            }

            // nungguin gimana cara simpen ke penyimpanan
            // check tiap slot apkah telah diisi atau belum

            // jika gagal{}

            // jika berhasil
            cout<<boughtItem<<" berhasil disimpan dalam penyimpanan!"<<endl;

        }
        

        
    }
    

    


}

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