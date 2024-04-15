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
    for(Role* Player:Players)
    [
        if (Player->GetRoleType()=="Petani"){
            Player->updateUmurTumbuhan();
        }
    ]
}

int main()
{
    Menu MenuGame;
    WordMachine machine1("Configuration//config//animal.txt");
    WordMachine machine2("Configuration//config//plant.txt");
    WordMachine machine3("Configuration//config//product.txt");
    WordMachine machine4("Configuration//config//recipe.txt");
    WordMachine machine5("Configuration//config//misc.txt");

    WordMachine machine6("Configuration//config//state.txt");
    

    vector<AnimalConfig> animalconfig = machine1.readAnimals();
    vector<PlantConfig> plantconfig = machine2.readPlants();
    vector<ProductConfig>productconfig = machine3.readProducts();
    vector<BuildingRecipeConfig> buildingconfig =machine4.readRecipes();
    MiscConfig miscconfig =machine5.readConfig();

    Store Toko(plantconfig,animalconfig);
    int targetGulden = miscconfig.getWinningMoney();
    int targetWeight = miscconfig.getWinningWeight();

    vector<Role*> Players = machine6.read_input(miscconfig,productconfig,animalconfig,plantconfig,buildingconfig,Toko);

    // muat
    

    urutPemain(Player);
    int currentPlayerIndex = 0;
    while(true){
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
            if (Players[currentPlayerIndex]->getRoleType()!="Walikota")
            {
                cout<<"Command hanya bisa dilakukan oleh walikota!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->pungutPajak(Players);
            }
            
        }
        else if(inputCommand == "CETAK_LADANG")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Petani")
            {
                cout<<"Command hanya bisa dilakukan oleh Petani!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->cetakLadang();
            }
        }
        else if(inputCommand == "CETAK_PETERNAKAN")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Farmer")
            {
                cout<<"Command hanya bisa dilakukan oleh Peternak!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->cetakPeternakan();
            }
        }
        else if(inputCommand == "TANAM")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Petani")
            {
                cout<<"Command hanya bisa dilakukan oleh Petani!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->Tanam();
            }
        }
        else if(inputCommand == "TERNAK")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Farmer")
            {
                cout<<"Command hanya bisa dilakukan oleh Peternak!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->Tanam();
            }
        }
        else if(inputCommand == "BANGUN")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Walikota")
            {
                cout<<"Command hanya bisa dilakukan oleh Walikota!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->bangunBangunan(buildingconfig);
            }
        }
        else if(inputCommand == "MAKAN")
        {

            Players[currentPlayerIndex]->makan();
        }
        else if(inputCommand == "KASIH_MAKAN")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Farmer")
            {
                cout<<"Command hanya bisa dilakukan oleh Peternak!"<<endl;
                
            }
            else{
                Players[currentPlayerIndex]->memberiPangan();
            }
        }
        else if(inputCommand == "BELI")
        {
            Players[currentPlayerIndex]->membeli();
        }
        else if(inputCommand == "JUAL")
        {
            Players[currentPlayerIndex]->menjual();
        }
        else if(inputCommand == "PANEN")
        {
            if (Players[currentPlayerIndex]->getRoleType()=="Farmer" || Players[currentPlayerIndex]->getRoleType()=="Petani")
            {
                Players[currentPlayerIndex]->Memanen();   
            }
            else{
                cout<<"Command hanya bisa dilakukan oleh Peternak dan Petani!"<<endl;
            }
        }
        else if(inputCommand == "SIMPAN")
        {
            cout<<"Menyimpan...";
        }
        else if(inputCommand == "TAMBAH_PEMAIN")
        {
            if (Players[currentPlayerIndex]->getRoleType()!="Walikota")
            {
                cout<<"Command hanya bisa dilakukan oleh Walikota!"<<endl;
                
            }
            else{
                Role* currentPlayer = Players[currentPlayerIndex];
                Players[currentPlayerIndex]->tambahPemain(Players);
                auto it = std::find(players.begin(), players.end(), currentPlayer);
                if (it != players.end()) {
                currentPlayerIndex = std::distance(players.begin(), it);
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
        else{
            cout<<"Command List salah!";
        }
        


    }
    return 0;
}
// NOTES INI HANYA KELAS COBA COBA UNTUK TEST WORDMACHINE