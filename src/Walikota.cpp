#include "../src/Role/Walikota.hpp"

int calculate_tax()
{
    return 0; // tidak ada tax dari walikota, hanya memungut
}

void Walikota::pungutPajak(std::vector<Role> daftarPemain)
{
    for (int i = 0; i < daftarPemain.size(); i++)
    {
        int pajakTemp = daftarPemain[i].calculate_tax();
        daftarPemain[i].setGulden(daftarPemain[i].getGulden() - pajakTemp);
    }
}

void Walikota::tambahPemain(std::vector<Role> daftarPemain)
{
    if (getGulden() < 50)
    {
        std::cout << "Uang tidak cukup!" << std::endl;
    }
    else
    {
        std::cout << "Masukkan jenis pemain: ";
        std::string jenis;
        std::cin >> jenis;
        std::string nama;
        std::cout << "Masukkan nama pemain: ";
        std::cin >> nama;
        if (jenis == "peternak")
        {
            daftarPemain.push_back(Farmer(nama, 50, 40, Inventory));
            std::cout << "Pemain baru ditambahkan!" << std::endl;
            std::cout << "Selamat datang " << nama << " di kota ini!" << std::endl;
        }
        else if (jenis == "petani")
        {
            daftarPemain.push_back(Petani(nama, 50, 40, Inventory))
                << "Pemain baru ditambahkan!" << std::endl;
            std::cout << "Selamat datang " << nama << " di kota ini!" << std::endl;
        }
        else
        {
            std::cout << "Tipe tidak valid!" << std::endl;
        }
    }
}

void Walikota::bangunBangunan(vector<BuildingRecipeConfig> recipes)
{
    std::cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    for (const auto &BuildingRecipeConfig : recipes)
    {
        BuildingRecipeConfig.display();
    }
    BuildingRecipeConfig *tempBuilding;
    std::cout << "Bangunan yang ingin dibangun: ";
    std::string kodehuruf;
    std::cin >> kodehuruf;
    bool ditemukan = false;
    bool cukupMaterial = true;
    for (auto &BuildingRecipeConfig : recipes)
    {
        if (BuildingRecipeConfig.getcode() == kodehuruf)
        {
            tempBuilding = new BuildingRecipeConfig(BuildingRecipeConfig); // g ada cc
            ditemukan = true;
            break;
        }
    }
    if (!(ditemukan)) // tidak ada
    {
        std::cout << "Kamu tidak punya resep bangunan tersebut!" << std::endl;
    }
    else
    {
        std::vector<Material> materials = tempBuilding->getmaterials();
        std::vector<Material> copyMaterials = tempBuilding->getmaterials();
        for (auto std::string : Inventory)
        {
            for (auto &material : copyMaterials)
            {
                if (material == string)
                {
                    material.quantity -= 1;
                }
            }
        }
        for (auto &material : copyMaterials)
        {
            if (material.quantity != 0)
            {
                cukupMaterial = false;
            }
        }
        if (!cukupMaterial) // tidak cukup material
        {
            std::cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
            for (auto &material : copyMaterials)
            {
                if (material.quantity != 0)
                {
                    std::cout << material.quantity << " " << material.name << ", ";
                }
                std::cout << std::endl;
            }
        }
        else
        {
            if (Inventory.isFull()) // penuh, blm ada fungsinya
            {
                std::cout << "Tidak ada tempat pada inventory"
            }
            else
            {
                Inventory.insert(tempBuilding); // blm ada fungsinya
                for (auto &material : materials)
                {
                    while (material.quantity != 0)
                    {
                        for (auto std::string : Inventory)
                        {
                            if (material.name == string)
                            {
                                string.delete(); // hapus dari inventory, blm ada fungsinya
                                material.quantity -= 1;
                            }
                        }
                    }
                }
                std::cout << tempBuilding->getcode << "berhasil dibangun dan telah menjadi hak milik walikota!" << std::endl;
            }
        }
    }
}