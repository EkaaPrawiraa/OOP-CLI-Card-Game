#include "Role/Petani.hpp"
#include <iostream>
#include <set>

Petani::Petani(string username, float weight, int uang, int storrows, int storcols, int ladrows, int ladcols)
    : Role(username, weight, uang, storrows, storcols), Ladang(ladrows, ladcols) {}

// Destructor implementation
Petani::~Petani() {}

// Virtual function implementations
void Petani::membeli(Store& Toko) {
 if (invent.isFull())
    {
        throw GameInvalidExc("Penyimpanan Anda Penuh tidak bisa melakukan pembelian");
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

        std::pair<int, Item*> passsss=Toko.buyItem(boughtItem,quantity,gulden,getRoleType());
        Item* item=passsss.second;
        int totalpaid = passsss.first;

        if (totalpaid>0)
        {
            
            this->gulden -= totalpaid;
            cout << endl;
            cout << "Selamat Anda berhasil membeli " << quantity << " " << boughtItem << ". Uang Anda tersisa " << this->gulden << " gulden." << endl;
            cout << endl;
            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;

            cetak_penyimpanan();

            cout<<endl;
            
            std::string location, kode;
            char col;
            int row;
            for(int i =1;i<=quantity;i++)
            {
                cout<<"Petak slot barang ke-"<<i<<" : ";
                std::cin >> location;
                
                col = std::toupper(location[0]);
                row = stoi(location.substr(1));
                std::regex pattern("^[a-zA-Z][0-9]+");
                while(!regex_match(location, pattern) || !invent.isemptyslot(row,col) ||  toupper(location[0]) - 'A' >invent.getCols() || row>invent.getRows())
                {   
                    if ((!regex_match(location, pattern))){
                        cout << "Format salah !"<< endl;  
                    }
                    else if(!invent.isemptyslot(row,col)){
                        cout << "Petak tersebut telah terisi!" << endl;
                    }
                    else if( toupper(location[0]) - 'A' >invent.getCols() || row>invent.getRows() ){
                        cout<<"Melebihi ukuran penyimpanan!"<<endl;
                    }

                    
                    cout << "Isi ulang!" <<endl;
                    cout<<"Petak slot barang ke-"<<i<<" : ";
                    cin >> location;
                    col = std::toupper(location[0]);
                    row = stoi(location.substr(1));
                    
                }

                invent.setValue(row,toupper(location[0]),item);
                cout<<boughtItem<<" berhasil disimpan dalam penyimpanan!"<<endl;
                cetak_penyimpanan();
                // cout<<item->getclassname();
  
            }
          
        }  
    }
    
}
    

void Petani::menjual(Store& Toko) {
     // Validasi tidak bisa menjual bangunan jika bukan walikota
    if (invent.countElement() == 0) {
        throw GameInvalidExc( "Penyimpanan Anda kosong tidak bisa melakukan penjualan");
    }
    
    int totalPrice = 0;
    
    int quanti;
    cetak_penyimpanan();
    cout << "Jumlah barang yang ingin anda jual : ";
    cin>>quanti;
    while (quanti>invent.countElement())
    {
        cout<<"Barang yang Anda miliki kurang!"<<endl;
        cout << "Jumlah barang yang ingin anda jual : ";
        cin>>quanti;
    }

    std::string location, kode;
    char col;
    int row;
    for(int i =1;i<=quanti;i++)
    {
                cout<<"Petak slot barang ke-"<<i<<" : ";
                std::cin >> location;
                
                col = std::toupper(location[0]);
                row = stoi(location.substr(1));
                std::regex pattern("^[a-zA-Z][0-9]+");
                while(!regex_match(location, pattern) || invent.isemptyslot(row,col) ||  toupper(location[0]) - 'A' >invent.getCols() || row>invent.getRows())
                {   
                    if ((!regex_match(location, pattern))){
                        cout << "Format salah !"<< endl;  
                    }
                    else if(invent.isemptyslot(row,col)){
                        cout << "Petak tersebut kosong!" << endl;
                    }
                    else if( toupper(location[0]) - 'A' >invent.getCols() || row>invent.getRows() ){
                        cout<<"Melebihi ukuran penyimpanan!"<<endl;
                    }
                    else{
                        cout << "Pastikan Item berupa Tumbuhan" << endl;
                    }
                    
                    cout << "Isi ulang!" <<endl;
                    cout<<"Petak slot barang ke-"<<i<<" : ";
                    cin >> location;
                    col = std::toupper(location[0]);
                    row = stoi(location.substr(1));
                    
                }

                if(invent.getValue(row,col)->getclassname()=="Building")
                {
                    throw GameInvalidExc("Petani tidak dapat menjual bangunan!");
                }
                else {
                    // cout << invent.getValue(row, tok[0])->getprice() << endl;
                    // Periksa tipe objek dan jualnya
                    totalPrice += Toko.sellItem(invent.getValue(row, location[0]));
                    invent.deleteValue(row,location[0]);

                }
                
    }
    this->gulden+=totalPrice;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalPrice << " gulden!" << endl;

    
}

int Petani::calculate_tax()
{
    int KTKP = 13;
   
    double KKP = 0.0;
    double pajak = 0.0;
    int netoKekayaan = gulden;
    
    // Hitung Neto
    for (const auto &row : invent.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            netoKekayaan+=cell.second->getprice();
        }
        
    }
    for (const auto &row : Ladang.getmatrix())
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
    std::set<std::string> uniqueCodes;
    std::string code;
    std::string name;
    for (const auto &row : Ladang.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            code = cell.second->getKode();
            name = cell.second->getname();
            if (uniqueCodes.find(code) == uniqueCodes.end()){
                std::cout << "- " << code << ": " << name << std::endl; 
                uniqueCodes.insert(code); 
            }
        }
    }
}


void Petani::Tanam(){
    if (Ladang.isFull()){
        throw GameInvalidExc("Peternakan Anda sudah penuh!");
    }
    cout << "Pilih tanaman dari penyimpanan" << endl;

    cetak_penyimpanan();
    std::string location;
    cout << "\n\nSlot: ";
    cin >> location;

    char col = std::toupper(location[0]);
    int row = stoi(location.substr(1));
    regex pattern("^[a-zA-Z][0-9]+");

    while(!regex_match(location, pattern) || invent.isemptyslot(row,col) || invent.getValue(row,col)->getclassname() != "Plant"  || toupper(location[0]) - 'A' >invent.getCols() || row>invent.getRows())
    {   
        if ((!regex_match(location, pattern))){
            cout << "Format salah !"<< endl;  
        }
        else if(invent.isemptyslot(row,col)){
            cout << "Petak tersebut kosong!" << endl;
        }
        else if( toupper(location[0]) - 'A' >invent.getCols() || row>invent.getRows() ){
            cout<<"Melebihi ukuran penyimpanan!"<<endl;
        }
        else{
            cout << "Pastikan Item berupa Tumbuhan" << endl;
        }
        
        cout << "Isi ulang!" <<endl;
        cout << "Slot: ";
        cin >> location;
        col = std::toupper(location[0]);
        row = stoi(location.substr(1));
        
    }

    cout << "Kamu memilih " << invent.getValue(row,col)->getname() << endl;

    std::cout << "Pilih petak tanah yang akan ditanami" << std::endl;
    Ladang.display("Ladang");
    std::cout << "\n\n";

    std::string loc;
    std::cout << "Pilih Petak: ";
    std::cin >> loc;

    char col1 = std::toupper(loc[0]);
    int row1 = stoi(loc.substr(1));

    while(!Ladang.isemptyslot(row1,col1)){
        std::cout << "Pastikan Petak Kosong" << std::endl;
        std::cout << "Pilih Petak: ";
        std::cin >> loc;
        col1 = std::toupper(loc[0]);
        row1 = stoi(loc.substr(1));
    }


    setLadang(row1, col1, dynamic_cast<Plant*>(invent.getValue(row, col)));

    invent.deleteValue(row,col);
    std::cout << "Cangkul, cangkul, cangkul yang dalam~!" << std::endl;
    std::cout << Ladang.getValue(row1,col1)->getname() << " berhasil ditanam!" << endl;
}
void Petani::Memanen(vector<ProductConfig> config){
    if(Ladang.isempty()){
        throw GameInvalidExc("Tidak ada yang bisa dipanen. Peternakan kosong.");
    }

    this->CetakLadang();
    std::cout << "\n\n";
    std::cout << "Pilih tanaman siap panen yang kamu miliki\n";

    //get listharvest()
    std::map<std::string, int> list;
    bool harvest = false;
    for (const auto &row : Ladang.getmatrix()) {
        for (const auto &cell : row.second) {
            if (cell.second->getumur() >= cell.second->getdurationtoharvest()) {
                harvest = true;
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

    if (!harvest){
        throw GameInvalidExc("Tidak ada yang bisa dipanen!");
    }
    
    // Menampilkan daftar tanaman siap panen
    int i = 1;
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << "  " << i << ". " << it->first << " (" << it->second << " Petak Siap Dipanen)" << std::endl;
        ++i;
    }

    int no, petak;
    std::cout << "Nomor tanaman yang ingin dipanen:";
    std::cin >> no;

    while(no > list.size() || no <= 0){
        std::cout << "Masukkan Nomor yang Valid!\n";
        std::cout << "Nomor tanaman yang ingin dipanen:";
        std::cin >> no;
    }

    std::cout << "Berapa petak yang ingin dipanen:";
    std::cin >> petak;

    auto it = list.begin();
    advance(it, no-1); // Menggerakkan iterator ke elemen yang sesuai
    while(petak > it->second || petak <= 0){
        std::cout << "Masukkan Jumlah Petak yang Valid!\n";
        std::cout << "Berapa petak yang ingin dipanen:";
        std::cin >> petak;
    }

    if(petak+invent.countElement() > invent.getSize()){
        throw GameInvalidExc( "Jumlah Penyimpanan Tidak Cukup!");
    }

    std::cout << "Pilih petak yang ingin dipanen:" << std::endl;
    std::string loc, kode;
    std::set<std::string> listloc;
    char col;
    int row;
    for(int i = 0; i < petak;i++){
        std::cout << "Petak ke-" << i+1 << ": ";
        std::cin >> loc;
        
        col = std::toupper(loc[0]);
        row = stoi(loc.substr(1));
        while(Ladang.isemptyslot(row,col) || Ladang.getValue(row,col)->getKode() != it->first )
        {   
            cout << "Masukkan Letak Petak yang Valid!" << endl;
            std::cout << "Petak ke-" << i+1 << ": ";
            std::cin >> loc;

            col = std::toupper(loc[0]);
            row = stoi(loc.substr(1));
        }

        listloc.insert(loc);
        Plant* plant = dynamic_cast<Plant*>(Ladang.getValue(row,col));
        Product* p = dynamic_cast<Product*>(plant->gethasilpanen(config));
        invent.setfirstempty(p);
        Ladang.deleteValue(row,col);
        
    }

    std::cout << petak <<" petak tanaman " << it->first << " pada petak ";
    for (auto it1 = listloc.begin(); it1 != listloc.end(); ++it1) {
        if (std::next(it1) == listloc.end()) {
            std::cout << *it1;
        } else {
            std::cout << *it1 << ", ";
        }
    } 
    std::cout << " telah dipanen!" << std::endl;
}


void Petani::updateUmurTumbuhan(){
    for (const auto &row : Ladang.getmatrix()) {
        for (const auto &cell : row.second) {
            cell.second->setumur(cell.second->getumur()+1);
        }
    }     
    
}

Matrix<Plant*> Petani::getLadang() const{
    return Ladang;
}