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
}
void Role::makan()
{
    // if (invent.isempty())
    // {
    //     // EXCEPTION
    //     throw MatrixKosongException();
    // }
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
    // if (!foundfood)
    // {
    //     // EXCEPTION BUAT
    //     throw NofoodException();
    // }
    cout << "Pilih makanan dari penyimpanan" << endl;
    cetak_penyimpanan();
    cout << endl
         << endl;
    string lokasi;
    bool found;
    int gain;
    do
    {
        std::cout << "Slot: ";
        std::cin >> lokasi;
        char column = lokasi[0];
        int row = stoi(lokasi.substr(1));
        found = false;
        if (auto product = dynamic_cast<Product *>(invent.getmatrix()[row][column]))
        {
            if (product->getadded_weight() != 0)
            {
                found = true;
                gain = product->getadded_weight();
                invent.deleteValue(row, column);
            }
        }

        // if (!found)
        // {
        //     // THROW EXCEPTION
        //     throw NofoodException();
        // }

    } while (!found);
    this->weight += gain;
}
void Role::membeli()
{
}
void Role::menjual()
{
}

std::string Role::getUsername()
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