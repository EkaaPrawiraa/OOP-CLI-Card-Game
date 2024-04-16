#include "Role/Role.hpp"

// dapat storrows dan storcols dari miscConfig
Role::Role(string username, float weight, int uang, int storrows, int storcols)
    : username(username), weight(weight), gulden(uang), invent(storrows, storcols) {}

Role::~Role() {}
void Role::next()
{
}
void Role::cetak_penyimpanan()
{
    invent.display("Penyimpanan");
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
void Role::makan()
{
    
    bool foundfood = false;
    for (const auto &row : invent.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            if (auto product = dynamic_cast<Product *>(cell.second))
            {
                if (product->getadded_weight() != 0)
                {
                    foundfood = true;
                    break;
                }
            }
        }
        if (foundfood)
        {
            break;
        }
    }
  
    if (!foundfood){
        throw GameInvalidExc("Minimal punya makan dek..");
    }
    else 
    {
        cout << "Pilih makanan dari penyimpanan" << endl;
        cetak_penyimpanan();
        cout << endl<< endl;
        
        
        int gain;
        bool found;
        do
        {
            
            string lokasi;
            std::cout << "Slot: ";
            std::cin >> lokasi;
            char column = lokasi[0];
            int row = stoi(lokasi.substr(1));
            found = false;
            if (invent.isemptyslot(row,column))
            {
                cout<<"Kamu mengambil harapan kosong dari penyimpanan."<<endl;
                cout<<"Silahkan masukan slot yang berisi makanan."<<endl;

            }
            else if (auto product = dynamic_cast<Product *>(invent.getValue(row,column)))
            {
                
                if (product->getadded_weight() != 0)
                {
                    found = true;
                    gain = product->getadded_weight();
                    cout<<"Dengan lahapnya, kamu memakanan hidangan itu"<<endl;
                    invent.deleteValue(row, column);
                }
                
            }
            else{
                    cout <<"Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!"<<endl;
                    cout<<"Silahkan masukan slot yang berisi makanan."<<endl;
                }
            

        }while (!found);
        this->weight += gain;
        cout<<"Alhasil, berat badan kamu naik menjadi "<<this->weight<<endl;
    }
    
}
void Role::membeli()
{
}
void Role::menjual()
{
}

std::string Role::getUsername() const
{
    return username;
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
    this->gulden = gulden;
}
void Role::setWeight(float weight)
{
    this->weight = weight;
}

string Role::getRoleType()
{
    return "Role";
}

Matrix<Item*>& Role::getInventory(){
    return invent;
}
Item* createItem(const std::vector<ProductConfig>& productConfigs, const std::vector<PlantConfig>& plantConfigs, const std::vector<AnimalConfig>& animalConfigs, const std::vector<BuildingRecipeConfig>& buildingConfigs, const std::string& itemName) {
    // Check if the item name matches any of the subclasses and create the corresponding object
    for (const auto& productConfig : productConfigs) {
        if (productConfig.getname() == itemName) {
            return new Product(productConfig.getcode(), productConfig.getname(), productConfig.gettype(), productConfig.getorigin(), productConfig.getaddedtoweight(), productConfig.getprice());
        }
    }


    for (const auto& plantConfig : plantConfigs) {
        if (plantConfig.getname() == itemName) {
            return new Plant(plantConfig.getcode(), plantConfig.getname(), plantConfig.gettype(), plantConfig.getdurationtoharvest(), plantConfig.getprice(), 0, " ");
        }
    }
    

    
    
    for (const auto& animalConfig : animalConfigs) {
        if (animalConfig.getname() == itemName) {
            return new Animal(animalConfig.getcode(), animalConfig.getname(), animalConfig.gettype(), animalConfig.getweighttoharvest(), animalConfig.getprice(), 0, "");
        }
    }
    

    for (const auto& buildingConfig : buildingConfigs) {
        if (buildingConfig.getname() == itemName) {
            return new Building(buildingConfig.getcode(), buildingConfig.getname(),  buildingConfig.getprice(), buildingConfig.getmaterials());
        }
    }
    
    // Item name does not match any subclass
    return nullptr;
}
