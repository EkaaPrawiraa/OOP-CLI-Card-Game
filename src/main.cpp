#include "Menu/Menu.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

std::string toUpper(const std::string& str) {
    std::string result = str;

    for (char& c : result) {
        c = std::toupper(c);
    }

    return result;
}

 bool compareRole(const Role* a, const Role* b) {
    return a->getUsername() < b->getUsername();
}

void urutPemain(std::vector<Role*>& roles) {
    std::sort(roles.begin(), roles.end(), compareRole);
}

void next(vector<Role*>& Players){
    for(Role* Player : Players)
    {
        Petani* petani = dynamic_cast<Petani*>(Player);
        if (petani)
        {
            petani->updateUmurTumbuhan();
        }
    }
}

bool isWinner(int moneyplayer,int weightplayer ,int targetmoney, int targetweight){
    return moneyplayer>=targetmoney && weightplayer >=targetweight;
}

void displayconfig(vector<AnimalConfig> a, 
                    vector<PlantConfig> p,
                    vector<ProductConfig> pr,
                    vector<BuildingRecipeConfig> b, 
                    MiscConfig m){
                    cout << "Animal Configurations:" << endl;
    for (const auto& animal : a) {
        animal.display();
    }
    
    cout << "\nPlant Configurations:" << endl;
    for (const auto& plant : p) {
        plant.display();
    }
    
    cout << "\nProduct Configurations:" << endl;
    for (const auto& product : pr) {
        product.display();
    }
    
    cout << "\nBuilding Recipe Configurations:" << endl;
    for (const auto& building : b) {
        building.display();
    }
    
    cout << "\Misc Configuration:" << endl;
    m.display();
                    }

int main()
{
    Menu MenuGame;
    WordMachine machine1("Configuration//config//animal.txt");
    WordMachine machine2("Configuration//config//plant.txt");
    WordMachine machine3("Configuration//config//product.txt");
    WordMachine machine4("Configuration//config//recipe.txt");
    WordMachine machine5("Configuration//config//misc.txt");

    
    

    vector<AnimalConfig> animalconfig = machine1.readAnimals();
    vector<PlantConfig> plantconfig = machine2.readPlants();
    vector<ProductConfig>productconfig = machine3.readProducts();
    vector<BuildingRecipeConfig> buildingconfig =machine4.readRecipes();
    MiscConfig miscconfig =machine5.readConfig();

    Store Toko(plantconfig,animalconfig);
    

    char answer;
    cout<<"Apakah Anda ingin memuat state? (y/n)";
    cin>>answer;
    std::string lokasi;
    if(toupper(answer)=='Y')
    {
        std::ifstream file;
        cout<<"Masukkan lokasi berkas state : ";
        cin>>lokasi;
        
    }
    else{
        cout<<"Anda memulai dengan  mode default!"<<endl;
        lokasi = "Configuration//config//default.txt";
    }
    WordMachine machine6(lokasi);
    vector<Role*> Players = machine6.read_input(miscconfig,productconfig,animalconfig,plantconfig,buildingconfig,Toko);

    urutPemain(Players);
    int currentPlayerIndex = 0;


    while(true){
       Role* curplay = Players[currentPlayerIndex];
       Walikota* walikota = dynamic_cast<Walikota*>(curplay);
       Petani* petani = dynamic_cast<Petani*>(curplay);
       Farmer* farmer = dynamic_cast<Farmer*>(curplay);
        string inputCommand;
        cout <<"> ";
        cin>>inputCommand;
        inputCommand = toUpper(inputCommand);
        if (inputCommand == "NEXT")
        {
            next(Players);
            currentPlayerIndex = (currentPlayerIndex + 1) % Players.size();
            std::cout << "Giliran dilanjut ke pemain: " << Players[currentPlayerIndex]->getUsername() << std::endl;
     
        }
        else if(inputCommand == "CETAK_PENYIMPANAN")
        {
            Players[currentPlayerIndex]->cetak_penyimpanan();
            
        }
        else if(inputCommand == "PUNGUT_PAJAK")
        {
            if ( !walikota)
            {
                cout<<"Command hanya bisa dilakukan oleh walikota!"<<endl;
                
            }
            else{
                walikota->pungutPajak(Players);
            }
            
        }
        else if(inputCommand == "CETAK_LADANG")
        {
            if (!petani)
            {
                cout<<"Command hanya bisa dilakukan oleh Petani!"<<endl;
                
            }
            else{
                petani->CetakLadang();
            }
        }
        else if(inputCommand == "CETAK_PETERNAKAN")
        {
            if (!farmer)
            {
                cout<<"Command hanya bisa dilakukan oleh Peternak!"<<endl;
                
            }
            else{
                farmer->cetakPeternakan();
            }
        }
        else if(inputCommand == "TANAM")
        {
            if (!petani)
            {
                cout<<"Command hanya bisa dilakukan oleh Petani!"<<endl;
                
            }
            else{
                petani->Tanam();
            }
        }
        else if(inputCommand == "TERNAK")
        {
            if (!farmer)
            {
                cout<<"Command hanya bisa dilakukan oleh Peternak!"<<endl;
                
            }
            else{
                farmer->Ternak();
            }
        }
        else if(inputCommand == "BANGUN")
        {
            if (!walikota)
            {
                cout<<"Command hanya bisa dilakukan oleh Walikota!"<<endl;
                
            }
            else{
                walikota->bangunBangunan(buildingconfig);
            }
        }
        else if(inputCommand == "MAKAN")
        {

            Players[currentPlayerIndex]->makan();
        }
        else if(inputCommand == "KASIH_MAKAN")
        {
            if (!farmer)
            {
                cout<<"Command hanya bisa dilakukan oleh Peternak!"<<endl;
                
            }
            else{
                farmer->memberiPangan();
            }
        }
        else if(inputCommand == "BELI")
        {
            if (farmer)
            {
               farmer->membeli(Toko);   
            }
            else if(petani)
            {
                petani->membeli(Toko);
            }
            else{
                walikota->membeli(Toko);
            }
        }
        else if(inputCommand == "JUAL")
        {
            if (farmer )
            {
               farmer->menjual(Toko);   
            }
            else if(petani)
            {
                petani->menjual(Toko);
            }
            else{
                walikota->menjual(Toko);
            }
        }
        else if(inputCommand == "PANEN")
        {
            if (farmer )
            {
               farmer->Memanen(productconfig);   
            }
            else if(petani)
            {
                petani->Memanen();
            }
            else{
                cout<<"Command hanya bisa dilakukan oleh Peternak dan Petani!"<<endl;
            }
        }
        else if(inputCommand == "SIMPAN")
        {
            string file;
            cout<<"Masukkan lokasi berkas state : ";
            cin>>file;
            machine6.save_input(file, Players, miscconfig, productconfig, animalconfig, plantconfig, buildingconfig, Toko);
            cout<<"Menyimpan..."<<endl;
            cout<<"State berhasil disimpan"<<endl;

        }
        else if(inputCommand == "TAMBAH_PEMAIN")
        {
            if (!walikota)
            {
                cout<<"Command hanya bisa dilakukan oleh Walikota!"<<endl;
                
            }
            else{
                Role* currentPlayer = Players[currentPlayerIndex];
                walikota->tambahPemain(Players,miscconfig);
                auto it = std::find(Players.begin(), Players.end(), currentPlayer);
                if (it != Players.end()) {
                currentPlayerIndex = std::distance(Players.begin(), it);
                }
        }
        }
        else if(inputCommand =="EXIT")
        {
            break;
        }
        else if (inputCommand=="DAFTAR_MENU")
        {
            cout<<"============MENU==========="<<endl;
        }
        else if(inputCommand=="INFO"){
            cout<<"=======Bio Player======="<<endl;
            cout<<"Informasi Player: "<<endl;
            cout << "Username: " << curplay->getUsername() << endl;
            cout << "Gulden: " << curplay->getGulden() << endl;
            cout << "Weight: " << curplay->getWeight()  << endl;
            curplay->cetak_penyimpanan();

            cout<<"\n\n\n";
            cout<<"=======Konfigurasi Game======="<<endl;
            displayconfig(animalconfig,plantconfig,productconfig,BuildingRecipeConfig,miscconfig);
            // kasihh buat display cnfig
        }
        else{
            cout<<"Command List salah!"<<endl;
        }
        
        if(isWinner(curplay->getGulden(),curplay->getWeight(),miscconfig.getWinningMoney(),miscconfig.getWinningWeight()))
        {
            cout<<curplay->getUsername()<<" is winning the game!!"<<endl;
        }

    }
    return 0;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE