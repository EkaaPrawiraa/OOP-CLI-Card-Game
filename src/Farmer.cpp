#include "Role/Farmer.hpp"
#include <string>
#include "Store/Store.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <regex>
#include <set>


Farmer::Farmer(string username, int gulden, float weight, int storrow, int storcol, int petrow, int petcol) 
    : Role(username, weight, gulden, storrow, storcol), Peternakan(petrow, petcol)
{
}

Farmer::~Farmer() {}


void Farmer::cetakPeternakan(){
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
                    std::cout << "- " << code << ": " << name << std::endl; 
                    uniqueCodes.insert(code); 
                }
            }
        }
    }

}


void Farmer::Ternak(){
    if (Peternakan.isFull())
    {
        cout << "Peternakan Anda sudah penuh!"<<endl;
        return;
    }
    // atasin kalo ladang penuh belum
    cout << "Pilih hewan dari penyimpanan" << endl;
    vector<Product*> pr;
    pr.push_back(new Product("ABW", "Bewe", "Material_Plant", "GNSH", 25.5, 15));
    Karnivora* sample = new Karnivora("ABD", "ABC", "TYPE", 15, 10, 15, "A02", pr);
    // Item* sample = new Item("ABD", "ABC", 15);
    invent.setValue(2, 'A', sample);
    cetak_penyimpanan();
    inputpetak:
    cout<<"Slot: ";
    string location;
    cin.ignore();
    cin>>location;
    int row = 0;
    std::regex pattern("^[a-zA-Z][0-9]+");
    if ((!std::regex_match(location, pattern))){
        cout << "Format salah !"<< endl;  
        goto inputpetak;
    }
    int col2 = toupper(location[0]) - 'A';
    row = std::stoi(location.substr(1));
    if (( col2>invent.getCols() || row>invent.getRows() ) ) {
        cout<<"Melebihi ukuran penyimpanan!"<<endl;
        goto inputpetak;
        }
    if (invent.isemptyslot(row, location[0])) {
            cout << "Petak tersebut kosong!" << endl;
            cout << "Isi ulang!" <<endl;
            goto inputpetak;
    } 
    if(invent.getValue(row,col2)->getclassname() != "Karnivora" && invent.getValue(row,col2)->getclassname() != "Herbivora"&& invent.getValue(row,col2)->getclassname() != "Omnivora")
    {   
        cout << "Pastikan Item berupa Hewan" << endl;
        cout << "Isi ulang!" <<endl;
        goto inputpetak;
        
    }
    char col = location[0];
    row = stoi(location.substr(1));
    cout << "Kamu memilih " << invent.getValue(row,col)->getname() << endl;

    std::cout << "Pilih petak tanah yang akan ditanami" << std::endl;
    Peternakan.display("Ladang");
    std::cout << "\n\n";

    std::string loc;
    std::cout << "Pilih Petak: ";
    std::cin >> loc;

    char col1 = loc[0];
    int row1 = stoi(loc.substr(1));

    while(!Peternakan.isemptyslot(row1,col1)){
        std::cout << "Pastikan Petak Kosong" << std::endl;
        std::cout << "Pilih Petak: ";
        std::cin >> loc;
        col1 = loc[0];
        row1 = stoi(loc.substr(1));
    }

    if(invent.getValue(row, col)->getclassname() == "Karnivora"){
        Peternakan.setValue(row1, col1, dynamic_cast<Karnivora*>(invent.getValue(row, col)));
    }
    else if (invent.getValue(row, col)->getclassname() == "Herbivora")
    {
        Peternakan.setValue(row1, col1, dynamic_cast<Herbivora*>(invent.getValue(row, col)));
    
    }
    else
    {
        Peternakan.setValue(row1, col1, dynamic_cast<Omnivora*>(invent.getValue(row, col)));
    }
    
    invent.deleteValue(row,col);
    std::cout << "Dengan hati-hati, kamu meletakkan seekor "<< Peternakan.getValue(row1,col1)->getname()<<" di kandang." << std::endl;
    std::cout << Peternakan.getValue(row1,col1)->getname() << " telah menjadi peliharaanmu sekarang!" << endl;

}

void Farmer::Memanen(){
    this->cetakPeternakan();
    std::cout << "\n\n";
    std::cout << "Pilih hewan siap panen yang kamu miliki\n";

    //get listharvest()
    std::map<std::string, int> list;

    for (const auto &row : Peternakan.getmatrix()) {
        for (const auto &cell : row.second) {
            if (cell.second->getberat() == cell.second->getweighttoharvest()) {
                auto it = list.find(cell.second->getKode());
                if (it != list.end()) {
                    // Jika sudah ada, tambahkan jumlahnya
                    it->second++;
                } else {
                    list[cell.second->getKode()] = 1;
                }
            }
        }
    }

    // Menampilkan daftar tanaman siap panen
    int i = 1;
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << "  " << i << ". " << it->first << " (" << it->second << " Petak Siap Dipanen)" << std::endl;
        ++i;
    }

    int no, petak;
    std::cout << "Nomor hewan yang ingin dipanen:";
    std::cin >> no;

    while(no > list.size() || no <= 0){
        std::cout << "Masukkan Nomor yang Valid!\n";
        std::cout << "Nomor hewan yang ingin dipanen:";
        std::cin >> no;
    }

    std::cout << "Berapa petak yang ingin dipanen:";
    std::cin >> petak;
    // validasi jumlah penyimpanan tidak cukup
    auto it = list.begin();
    advance(it, no-1); // Menggerakkan iterator ke elemen yang sesuai
    while(petak > it->second || petak <= 0){
        std::cout << "Masukkan Jumlah Petak yang Valid!\n";
        std::cout << "Berapa petak yang ingin dipanen:";
        std::cin >> petak;
    }

    if(petak+invent.countElement() > invent.getSize()){
        //Throw Exception
        std::cout << "Jumlah Penyimpanan Tidak Cukup!" << std::endl;
        return;
    }
    std::cout << "Pilih petak yang ingin dipanen:" << std::endl;
    std::string loc, kode;
    std::set<std::string> listloc;
    char col;
    int row;
    for(int i = 0; i < petak;i++){
        std::cout << "Petak ke-" << i+1 << ": ";
        std::cin >> loc;
        
        col = loc[0];
        row = stoi(loc.substr(1));
        while(Peternakan.isemptyslot(row,col) || Peternakan.getValue(row,col)->getKode() != it->first )
        {   
            cout << "Masukkan Letak Petak yang Valid!" << endl;
            std::cout << "Petak ke-" << i+1 << ": ";
            std::cin >> loc;

            col = loc[0];
            row = stoi(loc.substr(1));
        }

        listloc.insert(loc);
        for (Product* P:(Peternakan.getValue(row, col)->gethasilpanen()))
        {
            invent.setfirstempty(dynamic_cast<Product*>(P));
            
        }
        Peternakan.deleteValue(row,col);
        
    }

    std::cout << petak <<" petak hewan " << it->first << " pada petak ";
    for (auto it1 = listloc.begin(); it1 != listloc.end(); ++it1) {
        if (std::next(it1) == listloc.end()) {
            std::cout << *it1;
        } else {
            std::cout << *it1 << ", ";
        }
    } 
    std::cout << " telah dipanen!" << std::endl;
}

void Farmer::memberiPangan(int baris, int kolom)
{
    string petak;
    string slot;
    int beratAkhir;
    string hewanTerpilih;
    cout << "Pilih petak kandang yang akan ditinggali" << endl;
    cetakPeternakan();
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
                if (( col>invent.getCols() || row>invent.getRows() ) ) {
                    cout<<"Melebihi ukuran penyimpanan!"<<endl;
                    goto inputpetak;
                 }
                if (invent.isemptyslot(row, tok[0])) {
                     cout << "Petak tersebut kosong!" << endl;
                     cout << "Isi ulang!" <<endl;
                     goto inputpetak;
                } 
                else {
                    cout << invent.getValue(row, tok[0])->getprice() << endl;
                    // Periksa tipe objek dan jualnya
                    if (invent.getValue(row, tok[0])->getclassname() == "Building") {
                        Building* buildingItem = dynamic_cast<Building*>(invent.getValue(row, tok[0]));
                        if (buildingItem) {
                            totalPrice += Toko.sellItem(buildingItem); // Menjual objek Building
                        } else {
                            cout << "Gagal cast ke Building!" << endl;
                        }
                    } else if (invent.getValue(row, tok[0])->getclassname() == "Product") {
                        Product* productItem = dynamic_cast<Product*>(invent.getValue(row, tok[0]));
                        if (productItem) {
                            totalPrice += Toko.sellItem(productItem); // Menjual objek Product
                        } else {
                            cout << "Gagal cast ke Product!" << endl;
                        }
                    }

                }
                
    }
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalPrice << " gulden!" << endl;

    }
// void Farmer::menjual(Store& Toko) {
//     menjual<Item>(Toko);  
//     }

// template<typename T>
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
        
        Item* item;
        int totalpaid = Toko.buyItem(boughtItem,quantity,gulden,item);
        cout<<item->getname()<<endl;
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
                if (( col>invent.getCols() || row>invent.getRows() ) ) {
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
                    invent.setValue(row,tok[0],item);
                    cout<<boughtItem<<" berhasil disimpan dalam penyimpanan!"<<endl;
                    invent.display("Penyimpanan");

                }
                
            }
          
        }  
    }
    
}
    

// void Farmer::membeli(Store& Toko) {
//     membeli<Item>(Toko);  
//     }


int Farmer::calculate_tax()
{
    int KTKP = 11;
    int KKP = 0;
    int pajak = 0;
    int netoKekayaan = gulden;
    
    // Hitung Neto
    for (const auto &row : invent.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            netoKekayaan+=cell.second->getprice();
        }
        
    }
    for (const auto &row : Peternakan.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            netoKekayaan+=cell.second->getprice();
        }
        
    }

      
    // hitung neto kekayaan
    KKP = netoKekayaan - KTKP;

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