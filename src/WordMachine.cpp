#include "Utility/WordMachine.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <tuple>



using namespace std;

WordMachine::WordMachine(const string &filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        throw FileException("Gagal membuka file."); // handle pake exception
    }
}

WordMachine::~WordMachine()
{
    if (file.is_open())
    {
        file.close();
    }
}

vector<PlantConfig> WordMachine::readPlants()
{
    vector<PlantConfig> plants;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, durationToHarvest, price;
        string kodeHuruf, name, type;

        if (!(iss >> id >> kodeHuruf >> name >> type >> durationToHarvest >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
            continue;
        }

        plants.emplace_back(id, kodeHuruf, name, type, durationToHarvest, price);
    }

    return plants;
}
vector<AnimalConfig> WordMachine::readAnimals()
{
    vector<AnimalConfig> animals;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, weightToHarvest, price;
        string kodeHuruf, name, type;

        if (!(iss >> id >> kodeHuruf >> name >> type >> weightToHarvest >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
            continue;
        }

        animals.emplace_back(id, kodeHuruf, name, type, weightToHarvest, price);
    }

    return animals;
}
vector<ProductConfig> WordMachine::readProducts()
{
    vector<ProductConfig> products;
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int id, addedWeight, price;
        string kodeHuruf, name, type, origin;

        if (!(iss >> id >> kodeHuruf >> name >> type >> origin >> addedWeight >> price))
        {
            throw FileException("Format file plants tidak sesuai.");
            continue;
        }

        products.emplace_back(id, kodeHuruf, name, type, origin, addedWeight, price);
    }

    return products;
}
MiscConfig WordMachine::readConfig()
{
    int winningMoney, winningWeight, storageRows, storageCols, landRows, landCols, farmRows, farmCols;

    if (!(file >> winningMoney >> winningWeight >> storageRows >> storageCols >> landRows >> landCols >> farmRows >> farmCols))
    {
        throw FileException("Format file plants tidak sesuai.");
        return MiscConfig(0, 0, 0, 0, 0, 0, 0, 0);
    }

    return MiscConfig(winningMoney, winningWeight, storageRows, storageCols, landRows, landCols, farmRows, farmCols);
}





std::vector<BuildingRecipeConfig> WordMachine::readRecipes()
{
    std::vector<BuildingRecipeConfig> recipes;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int id, price;
        std::string kodeHuruf, name, materialName;
        std::vector<std::pair<std::string, int>> materials;

        if (!(iss >> id >> kodeHuruf >> name >> price))
        {
            throw FileException("Format file tidak sesuai.");
            continue;
        }

        while (iss >> materialName)
        {
            int quantity;
            if (!(iss >> quantity))
            {
                throw FileException("Format file tidak sesuai.");
                break;
            }
            materials.push_back(std::make_pair(materialName, quantity));
        }

        BuildingRecipeConfig recipe(id, kodeHuruf, name, price, materials);
        recipes.push_back(recipe);
    }

    file.close();
    return recipes;
}

std::vector<Role*> WordMachine::read_input(MiscConfig misc, const std::vector<ProductConfig>& pco, const std::vector<AnimalConfig>& aco, const std::vector<PlantConfig>& plco, const std::vector<BuildingRecipeConfig> bco , Store& toko) {
    std::vector<Role*> roles;
    // std::ifstream file;
    // file.open(filename);
    // std::cout<<"t1"<<std::endl;

    std::string line;
    // std::cout<<"t1,2"<<std::endl;
    while (std::getline(file, line)) {
        // std::cout<<"T1,5"<<std::endl;
        std::istringstream iss(line);
        int loopa;
        iss>>loopa;
        std::string username;
        // std::cout<<"Baris Pertama"<<loopa<<std::endl;
        // std::cout<<"t2"<<std::endl;
        for (int k=0;k<loopa;++k){
            // std::cout<<"t3"<<std::endl;
            std::getline(file, line);
            iss.clear();
            iss.str(line);
            iss >> username;
            std::string role_type;
            iss >> role_type;
            // std::cout<<username<<"USERNAME"<<role_type<<"ROLE"<<std::endl;
            if (role_type == "Petani") {
                std::string lokasi;float weight;
                int money, storrows, storcols, ladrows, ladcols, loop, umur;
                storrows = misc.getStorageRows();
                storcols = misc.getStorageCols();
                ladrows = misc.getLandRows();
                ladcols = misc.getLandCols();
                iss >> weight >> money;
                Petani* petani = new Petani(username, weight, money, storrows, storcols, ladrows, ladcols);
                std::getline(file, line);
                iss.clear();
                iss.str(line);
                iss >> loop;
                std::string itemsname;
                // Read ladang
                for (int i = 0; i < loop; ++i) {
                    std::getline(file, line);
                    iss.clear();
                    iss.str(line);
                    iss>>itemsname;
                    Item* p = createItem(pco, plco, aco, bco, itemsname);
                    petani->getInventory().setfirstempty(p);
                }
                std::getline(file, line);
                iss.clear();
                iss.str(line);
                iss >> loop;
                for (int i=0; i< loop; ++i){
                    std::getline(file, line);
                    iss.clear();
                    iss.str(line);
                    iss>>lokasi>>itemsname>>umur;
                    char col = lokasi[0];
                    int row = stoi(lokasi.substr(1));
                    Item* q = createItem(pco, plco, aco, bco, itemsname);
                    if (auto plant = dynamic_cast<Plant *>(q)){
                        plant->setumur(umur);
                        petani->setLadang(row, col, plant);
                    }
                }

                roles.push_back(petani);
            } else if (role_type == "Peternak") {
                std::string lokasi;float weight;
                int money, storrows, storcols, ladrows, ladcols, loop, umur;
                storrows = misc.getStorageRows();
                storcols = misc.getStorageCols();
                ladrows = misc.getFarmRows();
                ladcols = misc.getFarmCols();
                iss >> weight >> money;
                Farmer* petani = new Farmer(username, weight, money, storrows, storcols, ladrows, ladcols);
                std::getline(file, line);
                iss.clear();
                iss.str(line);
                iss >> loop;
                std::string itemsname;
                // Read ladang
                for (int i = 0; i < loop; ++i) {
                    std::getline(file, line);
                    iss.clear();
                    iss.str(line);
                    iss>>itemsname;
                    Item* p = createItem(pco, plco, aco, bco, itemsname);
                    petani->getInventory().setfirstempty(p);
                }
                std::getline(file, line);
                iss.clear();
                iss.str(line);
                iss >> loop;
                for (int i=0; i< loop; ++i){
                    std::getline(file, line);
                    iss.clear();
                    iss.str(line);
                    iss>>lokasi>>itemsname>>umur;
                    char col = lokasi[0];
                    int row = stoi(lokasi.substr(1));
                    Item* q = createItem(pco, plco, aco, bco, itemsname);
                    
                    if (auto plant = dynamic_cast<Animal *>(q)){
                        plant->setberat(umur);
                        petani->setTernak(row, col, plant);
                    }
                }
                roles.push_back(petani);
                // Similar logic for Farmer class
                // Implement it similarly to Petani
            } else if (role_type == "Walikota") {
                std::string lokasi;float weight;
                int money, storrows, storcols, loop, umur;
                storrows = misc.getStorageRows();
                storcols = misc.getStorageCols();
                iss >> weight >> money;
                Walikota* petani = new Walikota(username, weight, money, storrows, storcols);
                std::getline(file, line);
                iss.clear();
                iss.str(line);
                iss >> loop;
                std::string itemsname;
                // Read ladang
                for (int i = 0; i < loop; ++i) {
                    std::getline(file, line);
                    iss.clear();
                    iss.str(line);
                    iss>>itemsname;
                    Item* p = createItem(pco, plco, aco, bco, itemsname);
                    petani->getInventory().setfirstempty(p);
                }
                // Similar logic for Walikota class
                // Implement it similarly to Petani
                roles.push_back(petani);
            }
        }
        std::getline(file, line);
        iss.clear();
        iss.str(line);
        iss>>loopa;
        for (int i=0;i<loopa;++i){
            std::string itemsname;int jumlah;
            std::getline(file, line);
            iss.clear();
            iss.str(line);
            iss>>itemsname>>jumlah;
            Item* p = createItem(pco, plco, aco, bco, itemsname);
            if (Building* building = dynamic_cast<Building*>(p)) {
                for (int ab=0;ab<jumlah;++ab){
                    toko.addBuilding(*building);
                }
            }else if (Product* product = dynamic_cast<Product*>(p)){
                for (int ab=0;ab<jumlah;++ab){
                    toko.addProduct(*product);
                }
            }
        }
    }

    file.close();
    return roles;
}
void WordMachine::save_input(const std::string& filename, const std::vector<Role*>& roles, const MiscConfig& misc, const std::vector<ProductConfig>& pco, const std::vector<AnimalConfig>& aco, const std::vector<PlantConfig>& plco, const std::vector<BuildingRecipeConfig>& bco, const Store& toko) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    file << roles.size() << std::endl;
    // Write roles
    for (const auto& role : roles) {
        file <<  role->getUsername()  << " " << role->getRoleType() << " " << role->getGulden() << " " << role->getWeight() << std::endl;

        // Write inventory
        Matrix<Item*> inventory = role->getInventory();
        file << inventory.countElement() << std::endl;
        for (const auto &row : inventory.getmatrix())
        {
            for (const auto &cell : row.second)
            { 
                const Item* item = cell.second;
                file << item->getname() << std::endl;
            }
        }
        // Write specific role details
        if (const Petani* petani = dynamic_cast<const Petani*>(role)) {
            // Write Petani details
            // Write ladang details
            file << petani->getLadang().countElement() << std::endl;
            for (const auto &row : petani->getLadang().getmatrix())
            {
                for (const auto &cell : row.second)
                { 
                    const Plant* plant=cell.second;
                    file << cell.first << row.first << " " << plant->getname() << " " << plant->getumur() << std::endl;
                }
            }
        } else if (const Farmer* farmer = dynamic_cast<const Farmer*>(role)) {
            // Write Farmer details
            // Write ternak details
            file << farmer->getpeternakan().countElement() << std::endl;
            for (const auto &row : farmer->getpeternakan().getmatrix())
            {
                for (const auto &cell : row.second)
                { 
                    const Animal* animal = cell.second;
                    file << cell.first << row.first << " " << animal->getname() << " " << animal->getberat() << std::endl;
                }
            }
        }
    }

    // Write additional items in the store
    file << toko.getbuilding().size() + toko.getproduct().size() << std::endl;
    vector<std::string> done;
    for (const auto& building : toko.getbuilding()) {
        auto it = std::find(done.begin(), done.end(), building.getname());
        if (it == done.end()){
            file << building.getname() << " " << toko.getJumlah(building.getKode()) << std::endl;
            done.push_back(building.getname());
        }
    }
    for (const auto& product : toko.getproduct()) {
        auto it = std::find(done.begin(), done.end(), product.getname());
        if (it==done.end()){
            file << product.getname() << " " << toko.getJumlah(product.getKode()) << std::endl;
            done.push_back(product.getname());
        }
    }

    file.close();
}
