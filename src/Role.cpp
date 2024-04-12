#include "Role/Role.hpp"

Role::Role(string username, float weight, int uang, Matrix invent, vector<Product> items)
{
    this->username = username;
    this->weight = weight;
    this->gulden = uang;
    this->invent = invent;
    this->Items = items;
}
Role::~Role() {}
void Role::next()
{
}
void Role::cetak_penyimpanan()
{
    invent.display("Penyimpanan");
}
void Role::makan()
{
    if(Items.empty()){
        //EXCEPTION
        cout<<"Inventori Kosong"<<endl;
        return;
    }
    bool foundfood=false;
    for (Product item : Items){
        if (item.getadded_weight()!=0){
            foundfood=true;
            break;
        }
    }
    if (!foundfood){
        //EXCEPTION BUAT
        cout<<"Tidak ada makanan di inventori"<<endl;
        return;
    }
    cout<< "Pilih makanan dari penyimpanan"<<endl;
    cetak_penyimpanan();
    cout<<endl<<endl;
    string lokasi;
    bool found;
    int gain;
    do {
        std::cout << "Slot: ";
        std::cin >> lokasi;

        found = false;
        for (auto it = Items.begin(); it != Items.end(); ++it) {
            if (it->getlocation() == lokasi && it->getadded_weight() != 0) {
                found = true;
                gain=it->getadded_weight();
                Items.erase(it);
                break;
            }
        }

        if (!found) {
            //THROW EXCEPTION
            std::cout << "Tidak ditemukan makanan di lokasi" << std::endl;
        }

    } while (!found);
    this->weight+=gain;

    



}
void Role::membeli()
{
}
void Role::menjual()
{
}
int Role::getGulden()
{
    return gulden;
}
float Role::getWeight()
{
    return weight;
}
void Role::setGulden(int gulden)
{
    this->gulden=gulden;
}
void Role::setWeight(float weight)
{
    this->weight=weight;
}
Matrix Role::getInventory()
{
    return invent;
}
