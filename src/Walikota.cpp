#include "Role/Walikota.hpp"

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

void Walikota::tambahPemain(std::vector<Role> daftarPemain, std::vector<Plant> tanaman)
{
    Matrix *tempMatriks = new Matrix(); // parameter matriks (inventory, plant)
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
            daftarPemain.push_back(Farmer(nama, 50, 40, *tempMatriks));
            std::cout << "Pemain baru ditambahkan!" << std::endl;
            std::cout << "Selamat datang " << nama << " di kota ini!" << std::endl;
        }
        else if (jenis == "petani")
        {
            Role *tempPetani = new Petani(nama, 50, 40, *tempMatriks, tanaman, *tempMatriks);
            daftarPemain.push_back(*tempPetani);
            std::cout << "Pemain baru ditambahkan!" << std::endl;
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
    Matrix inventory = getInventory();
    std::vector<std::vector<std::tuple<std::string, std::string, std::string>>> inventoryMap = inventory.getMatrix();
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
    for (int i = 0; i < recipes.size(); i++)
    {
        if (recipes[i].getcode() == kodehuruf)
        {
            tempBuilding = new BuildingRecipeConfig(recipes[i]); // g ada cc
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
        for (int i = 0; i < inventory.getRows(); i++)
        {
            for (int j = 0; j < inventory.getCols(); j++)
            {
                for (auto &material : copyMaterials)
                {
                    if (material.name == inventoryMap[i][j]) // blm bener, bingung struktur matriks yang bener
                    {
                        material.quantity -= 1;
                    }
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
            if (inventory.isFull()) // penuh
            {
                std::cout << "Tidak ada tempat pada inventory";
            }
            else
            {
                inventory.setfirstempty(tempBuilding->getcode()); // masukkan dalam inventory
                // prosedur menghapus material pada inventory yang dibutuhkan untuk membangun
                for (int i = 0; i < inventory.getRows(); i++)
                {
                    for (int j = 0; j < inventory.getCols(); j++)
                    {
                        for (auto &material : materials)
                        {
                            if (material.name == inventoryMap[i][j]) // blm bener, bingung struktur matriks yang bener
                            {
                                inventory.deleteString(material.name);
                                material.quantity -= 1;
                            }
                        }
                    }
                }
                std::cout << tempBuilding->getcode() << "berhasil dibangun dan telah menjadi hak milik walikota!" << std::endl;
            }
        }
    }
}