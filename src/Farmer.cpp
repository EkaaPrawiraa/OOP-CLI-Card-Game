#include "Role/Farmer.hpp"
#include <string>
#include "Store/Store.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <regex>
#include <set>

using namespace std;

Farmer::Farmer(string username, int gulden, float weight, int storrow, int storcol, int petrow, int petcol) 
    : Role(username, weight, gulden, storrow, storcol), Peternakan(petrow, petcol)
{
}

Farmer::~Farmer() {}


void Farmer::cetakPeternakan(int baris,int kolom){
    Peternakan.display("Peternakan");
    std::cout << "\n\n";
    std::set<std::string> uniqueCodes;
    std::string code;
    std::string name;
    for (const auto &row : invent.getmatrix())
    {
        for (const auto &cell : row.second)
        { 
            code = cell.second->getKode();
            name = cell.second->getname();
            if (code != "   ") { 
                if (uniqueCodes.find(code) == uniqueCodes.end()){
                    std::cout << "- " << code << ": " << name << std::endl; // Cetak kode tanaman
                    uniqueCodes.insert(code); // Tambahkan kode tanaman ke set
                }
            }
        }
    }

}

void Farmer::ternak(int baris, int kolom)
{
    // Jika tidak ada hewan di penyimpanan, perintah tidak dapat dilakukan.
    // Jika kandang penuh, perintah tidak dapat dilakukan.
    cout<<"Pilih hewan dari penyimpanan"<<endl;
    Farmer::cetak_penyimpanan();
    string slot;
    string lokasi;
    string hewanTerpilih;
    // ambill dari penyimpanan
    cout << "Slot: ";
    cin >> slot;
    // check if valid
    // nunggu inventory
    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    Farmer::cetakPeternakan(baris, kolom);
    cout << "Petak tanah: ";
    cin >> lokasi;
    // check if valid

    cout << "\nDengan hati-hati, kamu meletakkan seekor" << hewanTerpilih << " di kandang" << endl;
    cout << hewanTerpilih << " telah menjadi peliharaanmu sekarang!" << endl;
}
void Farmer::memberiPangan(int baris, int kolom)
{
    string petak;
    string slot;
    int beratAkhir;
    string hewanTerpilih;
    cout << "Pilih petak kandang yang akan ditinggali" << endl;
    cetakPeternakan(baris, kolom);
    cout << "Petak kandang: " << endl;
    cin >> petak;
    // validasi pemilihan
    cout << "Kamu memilih " << hewanTerpilih << " untuk diberi makan." << endl;
    cout << "Pilih pangan yang akan diberikan" << endl;

    cetak_penyimpanan();
    cout << "Slot: ";
    cin >>slot;
    // validasi tiap input
    cout << hewanTerpilih << " sudah diberi makan dan beratnya menjadi " << beratAkhir << endl;
}



void Farmer::menjual(Store& Toko) {
    // Validasi tidak bisa menjual bangunan jika bukan walikota
    if (invent.countElement() == 0) {
        cout << "Penyimpanan Anda kosong tidak bisa melakukan penjualan" << endl;
        return;
    }
    
    int totalPrice = 0;
    
    int quanti;
    invent.display("Penyimpanan");
    cout << "Jumlah barang yang ingin anda jual : ";
    cin>>quanti;
    while (quanti>invent.countElement())
    {
        cout<<"Barang yang Anda miliki kurang!"<<endl;
        cout << "Jumlah barang yang ingin anda jual : ";
        cin>>quanti;
    }
    for(int i =1;i<=quanti;i++)
    {
                inputpetak:
                cout<<"Petak slot barang ke-"<<i<<" : ";
                string tok;
                cin.ignore();
                cin>>tok;
                cout<<tok<<endl;
                std::regex pattern("^[a-zA-Z][0-9]+");
                if ((!std::regex_match(tok, pattern))){
                    cout << "Format salah !"<< endl;  
                    goto inputpetak;
                }
                int col = toupper(tok[0]) - 'A';
                int row = std::stoi(tok.substr(1));
                if (( col>invent.getCol() || row>invent.getRow() ) ) {
                    cout<<"Melebihi ukuran penyimpanan!"<<endl;
                    goto inputpetak;
                 }
                if (invent.isemptyslot(row, tok[0])) {
                     cout << "Petak tersebut kosong!" << endl;
                     cout << "Isi ulang!" <<endl;
                     goto inputpetak;
                } 
                else {
                    
                    totalPrice+= Toko.sellItem(*invent.getValue(row, tok[0]));
                    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalPrice << " gulden!" << endl;

                }
                
    }

    }
// void Farmer::menjual(Store& Toko) {
//     menjual<Item>(Toko);  
//     }

template<typename T>
void Farmer::membeli(Store& Toko){
    if (invent.isFull())
    {
        cout << "Penyimpanan Anda Penuh tidak bisa melakukan pembelian" << endl;
    }
    else
    {

        Toko.display();
        cout<<"\n\n";
        cout <<"Uang Anda : "<<this->gulden<<endl;
        cout<<"Slot penyimpanan tersedia: "<<invent.getSize()-invent.countElement()<<endl;
        string boughtItem;
        cout << "Kode barang yang ingin dibeli : ";
        cin >> boughtItem;
        int quantity = 0;
        cout<<"Kuantitas : ";
        cin >>quantity;
        while(invent.countElement()+quantity>invent.getSize())
        {
            cout<<"Penyimpanan anda tidak cukup!"<<endl;
            cout<<"Sisa penyimpanan : "<<invent.getSize()-invent.countElement()<<endl;
            cout<<"Kuantitas : ";
            cin >>quantity;
        }
        
        T item;
        int totalpaid = Toko.buyItem(boughtItem,quantity,gulden,item);
        if (totalpaid>0)
        {
            
            this->gulden -= totalpaid;
            cout << endl;
            cout << "Selamat Anda berhasil membeli " << quantity << " " << boughtItem << ". Uang Anda tersisa " << this->gulden << " gulden." << endl;
            cout << endl;
            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
            // belum tau cetak penyimpanan
            invent.display("Penyimpanan");
            // atur cetak penyimpanan
            cout<<endl;
            

            for(int i =1;i<=quantity;i++)
            {
                inputpetak:
                cout<<"Petak slot barang ke-"<<i<<" : ";
                string tok;
                cin.ignore();
                cin>>tok;
                std::regex pattern("^[a-zA-Z][0-9]+");
                if ((!std::regex_match(tok, pattern))){
                    cout << "Format salah !"<< endl;  
                    goto inputpetak;
                }
                int col = toupper(tok[0]) - 'A';
                int row = std::stoi(tok.substr(1));
                if (( col>invent.getCol() || row>invent.getRow() ) ) {
                    cout<<"Melebihi ukuran penyimpanan!"<<endl;
                    goto inputpetak;
                 }
                if (!invent.isemptyslot(row,tok[0]))
                {
                    cout << "Petak tersebut telah terisi!"<<endl;
                    cout << "Isi ulang!" <<endl;
                    goto inputpetak;
                }
                else {
                    invent.setValue(row,tok[0],&item);
                    cout<<boughtItem<<" berhasil disimpan dalam penyimpanan!"<<endl;

                }
                
            }
          
        }  
    }
    
}
    

void Farmer::membeli(Store& Toko) {
    membeli<Item>(Toko);  
    }


int Farmer::calculate_tax()
{
    int KTKP = 11;
    int KKP = 0;
    int pajak = 0;
    int netoKekayaan = 0;

    netokekayaan =    
    // hitung neto kekayaan
    KKP = netoKekayaan - KTKP;
    // atur jika gulden kurang tapi kekaayaan banyak

    if (KKP <= 0)
    {
        pajak = 0;
    }
    else if (KKP <= 6)
    {
        pajak = 0.05;
    }
    else if (KKP <= 25)
    {
        pajak = 0.15;
    }
    else if (KKP <= 50)
    {
        pajak = 0.25;
    }
    else if (KKP <= 500)
    {
        pajak = 0.30;
    }
    else
    {
        pajak = 0.35;
    }

    int bayarPajak = round(pajak * KKP);
    if (getGulden() - bayarPajak < 0)
    {
        bayarPajak = getGulden();
        setGulden(0);
        return bayarPajak;
    }
    else
    {
        setGulden(getGulden() - bayarPajak);
        return bayarPajak;
    }
}

string Farmer::getRoleType()
{
    return "Farmer";
}