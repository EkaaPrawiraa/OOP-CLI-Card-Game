#include "Role/Petani.hpp"
#include <iostream>
#include <set>
#include "Storage/Storage.hpp"

Petani::Petani(string username, float weight, int uang, int storrows, int storcols, int ladrows, int ladcols) 
: Role(username, weight, uang, storrows, storcols), Ladang(ladrows, ladcols){}

// Destructor implementation
Petani::~Petani(){}

// Virtual function implementations
void Petani::next(){}
void Petani::membeli(){}
void Petani::menjual(){}

int Petani::calculate_tax() {
    // Implementation of tax calculation goes here
    return 0; // Placeholder return value
}

void Petani::setLadang(int row, char col, Plant* p){
    Ladang.setValue(row,col, p);

}

// Non-virtual function implementations
void Petani::CetakLadang(){
    Ladang.display("Ladang");
    std::cout << "\n\n";
    //Penulisan semua kodehutuf yang ada di matrix, jika ada kode yang sama di dua tempat atay lebih, tuliskan hanya satu kode saja
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
    cout << "Pilih tanaman dari penyimpanan" << endl;
    Product pr("ABW", "Bewe", "Material_Plant", "GNSH", 25.5, 15);
    MaterialPlant* sample = new MaterialPlant("ABD", "ABC", "TYPE", 15, 10, 15, "A02", pr);
    // Item* sample = new Item("ABD", "ABC", 15);
    invent.setValue(2, 'A', sample);
    cetak_penyimpanan();

    std::string location;
    cout << "Slot: ";
    cin >> location;

    char col = location[0];
    int row = stoi(location.substr(1));


    while(invent.isemptyslot(row,col) || invent.getValue(row,col)->getclassname() != "MaterialPlant" && invent.getValue(row,col)->getclassname() != "FruitPlant")
    {   
        cout << "Pastikan Item berupa Tumbuhan" << endl;
        cout << "Slot: ";
        cin >> location;
        col = location[0];
        row = stoi(location.substr(1));
        
    }

    cout << "Kamu memilih " << invent.getValue(row,col)->getname() << endl;

    std::cout << "Pilih petak tanah yang akan ditanami" << std::endl;
    Ladang.display("Ladang");
    std::cout << "\n\n";

    std::string loc;
    std::cout << "Pilih Petak: ";
    std::cin >> loc;

    char col1 = loc[0];
    int row1 = stoi(loc.substr(1));

    while(!Ladang.isemptyslot(row1,col1)){
        std::cout << "Pastikan Petak Kosong" << std::endl;
        std::cout << "Pilih Petak: ";
        std::cin >> loc;
        col1 = loc[0];
        row1 = stoi(loc.substr(1));
    }

    if(invent.getValue(row, col)->getclassname() == "MaterialPlant"){
        Ladang.setValue(row1, col1, dynamic_cast<MaterialPlant*>(invent.getValue(row, col)));
    }
    else{
        Ladang.setValue(row1, col1, dynamic_cast<FruitPlant*>(invent.getValue(row, col)));
    }
    
    invent.deleteValue(row,col);
    std::cout << "Cangkul, cangkul, cangkul yang dalam~!" << std::endl;
    std::cout << Ladang.getValue(row1,col1)->getname() << " berhasil ditanam!" << endl;
}
void Petani::Memanen(){
    this->CetakLadang();
    std::cout << "\n\n";
    std::cout << "Pilih tanaman siap panen yang kamu miliki\n";

    //get listharvest()
    std::map<std::string, int> list;

    for (const auto &row : Ladang.getmatrix()) {
        for (const auto &cell : row.second) {
            if (cell.second->getumur() == cell.second->getdurationtoharvest()) {
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
        while(Ladang.isemptyslot(row,col) || Ladang.getValue(row,col)->getKode() != it->first )
        {   
            cout << "Masukkan Letak Petak yang Valid!" << endl;
            std::cout << "Petak ke-" << i+1 << ": ";
            std::cin >> loc;

            col = loc[0];
            row = stoi(loc.substr(1));
        }

        listloc.insert(loc);
        invent.setfirstempty(dynamic_cast<Product*>(Ladang.getValue(row, col)->gethasilpanen()));
        setWeight(getWeight()+Ladang.getValue(row, col)->gethasilpanen()->getadded_weight());
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
