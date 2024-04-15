// #include "Role/Walikota.hpp"

// int Walikota::jumlah = 0;

// // seperti role
// // Walikota::Walikota(string username, float weight, int uang, int storrows, int storcols) : Role(username, weight, uang, storrows, storcols)
// // {
// //     jumlah++;
// // }

// Walikota::Walikota(string username, float weight, int uang, int storrows, int storcols) : Role(username, weight, uang, storrows, storcols)
// {
//     jumlah++;
// }

// // panggil constructor pakai ini
// Walikota Walikota::conditionalConstructor(string username, float weight, int uang, int storrows, int storcols)
// {
//     if (Walikota::jumlah == 0)
//     {
//         std::cout << "Walikota telah berhasil dibuat" << std::endl;
//         return Walikota(username, weight, uang, storrows, storcols);
//     }
//     else // walikota sudah dibuat (exception)
//     {
//         throw std::runtime_error("Walikota sudah ada!");
//     }
// }

// Walikota::~Walikota()
// {
//     // vector tidak perlu destructor
//     // inventory dihapus di role harusnya
//     std::cout << "Walikota dihapus" << std::endl;
// }

// void Walikota::next()
// {
//     // standar -> hanya item plant -> implementasi di role?
// }

// int Walikota::calculate_tax()
// {
//     // tidak ada tax dari walikota, hanya memungut
//     return 0;
// }

// bool Walikota::compareTaxTuples(std::tuple<Role *, int> a, std::tuple<Role *, int> b)
// {
//     // menurun secara jumlah
//     if (std::get<1>(a) != std::get<1>(b))
//     {
//         return std::get<1>(a) > std::get<1>(b);
//     }
//     // nama secara menaik
//     return std::get<0>(a)->getUsername() < std::get<0>(b)->getUsername();
// }

// void Walikota::pungutPajak(std::vector<Role *> daftarPemain)
// {
//     std::cout << "Cring cring cring..." << std::endl;
//     std::cout << "Pajak sudah dipungut!" << std::endl;
//     std::cout << std::endl;
//     std::cout << "Berikut adalah detil dari pemungutan pajak:" << std::endl;
//     int totalPajak = 0;
//     // vector pajak untuk pengurutan
//     std::vector<std::tuple<Role *, int>> vectorPajak;
//     // iterasi setiap pemain
//     int pajakTemp = 0;
//     for (int i = 0; i < daftarPemain.size(); i++)
//     {
//         // pengecekan apakah Role berupa walikota
//         // tidak pakai exception jika berupa walikota
//         if (daftarPemain[i]->getRoleType() != "Walikota")
//         {
//             // hitung pajak setiap pemain
//             pajakTemp = daftarPemain[i]->calculate_tax();
//             // testing
//             // std::cout << daftarPemain[i]->getUsername() << "pajak " << pajakTemp << std::endl;
//             // std::cout << "sisa gulden" << daftarPemain[i]->getGulden() << std::endl;
//             // // pengecekan ketersediaan gulden (dalam petani farmer / pungutPajak)
//             // if (daftarPemain[i]->getGulden() < pajakTemp)
//             // {
//             //     pajakTemp = daftarPemain[i]->getGulden();
//             // }
//             // tambah dalam vector pajak
//             vectorPajak.push_back(std::make_tuple(daftarPemain[i], pajakTemp));
//             // // aplikasikan pada pemain
//             // daftarPemain[i]->setGulden(daftarPemain[i]->getGulden() - pajakTemp);
//             // total jumlah pajak

//             totalPajak += pajakTemp;
//         }
//     }
//     // pengurutan vector sesuai ketentuan
//     std::sort(vectorPajak.begin(), vectorPajak.end(), Walikota::compareTaxTuples);
//     // display hasil
//     for (int i = 0; i < vectorPajak.size(); i++)
//     {
//         std::cout << i + 1 << ". " << std::get<0>(vectorPajak[i])->getUsername() << " - "
//                   << std::get<0>(vectorPajak[i])->getRoleType()
//                   << ": " << std::get<1>(vectorPajak[i]) << " gulden" << std::endl;
//     }
//     std::cout << std::endl;
//     std::cout << "Negara mendapatkan pemasukan sebesar " << totalPajak << " gulden." << std::endl;
//     std::cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << std::endl;
//     // tambah ke uang walikota
//     setGulden(getGulden() + totalPajak);
// }

// bool Walikota::nameExists(std::string name, std::vector<Role *> daftarPemain)
// {
//     bool found = false;
//     int i = 0;
//     while (i < daftarPemain.size() && !found)
//     {
//         if (daftarPemain[i]->getUsername() == name)
//         {
//             found = true;
//             break;
//         }
//         i++;
//     }
//     return found;
// }

// bool Walikota::sortUsername(Role *a, Role *b)
// {
//     return a->getUsername() < b->getUsername();
// }

// void Walikota::tambahPemain(std::vector<Role *> &daftarPemain)
// {
//     if (getGulden() < 50) // kurang uang untuk menambah pemain (exception)
//     {
//         std::cout << "Uang tidak cukup!" << std::endl;
//     }
//     else
//     {
//         std::cout << "Masukkan jenis pemain: ";
//         std::string jenis;
//         std::cin >> jenis;
//         if (jenis != "peternak" && jenis != "petani") // jenis tidak valid (exception)
//         {
//             throw std::runtime_error("jenis tidak valid!");
//         }
//         else // lanjut
//         {
//             std::string nama;
//             std::cout << "Masukkan nama pemain: ";
//             std::cin >> nama;
//             if (nameExists(nama, daftarPemain)) // nama sudah ada (exception)
//             {
//                 std::cout << "Nama pemain sudah ada!" << std::endl;
//             }
//             else
//             {
//                 if (jenis == "peternak")
//                 {
//                     Farmer *tempPeternak = new Farmer(nama, 50, 40, 8, 8, 8, 8);
//                     daftarPemain.push_back(tempPeternak);
//                 }
//                 else if (jenis == "petani")
//                 {
//                     Petani *tempPetani = new Petani(nama, 50, 40, 8, 8, 8, 8); // bingung constructor petani
//                     daftarPemain.push_back(tempPetani);
//                 }
//                 // pengurutan urutan pemain (jika ada pemain baru yang ditambahkan)
//                 std::cout << "Pemain baru ditambahkan!" << std::endl;
//                 std::cout << "Selamat datang " << nama << " di kota ini!" << std::endl;
//                 std::sort(daftarPemain.begin(), daftarPemain.end(), Walikota::sortUsername);
//                 // mengurangi uang dari walikota
//                 setGulden(getGulden() - 50);
//             }
//         }
//     }
// }

// void Walikota::bangunBangunan(vector<BuildingRecipeConfig> recipes)
// {
//     Matrix<Item *> inventory = getInventory();
//     std::map<int, std::map<char, Item *>> matriksInventory = inventory.getmatrix();

//     // tampilan semua resep bangunan dari config
//     std::cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
//     for (const auto &BuildingRecipeConfig : recipes)
//     {
//         BuildingRecipeConfig.display();
//     }

//     // terima masukan kode bangunan yang ingin dibangun
//     std::cout << "Bangunan yang ingin dibangun: ";
//     std::string kodehuruf;
//     std::cin >> kodehuruf;
//     bool ditemukan = false;
//     bool cukupMaterial = true;
//     // pencarian kode bangunan pada config
//     BuildingRecipeConfig *tempBuildingConfig;
//     for (int i = 0; i < recipes.size(); i++)
//     {
//         if (recipes[i].getcode() == kodehuruf)
//         {
//             tempBuildingConfig = new BuildingRecipeConfig(recipes[i]); // cc dari config (tipe config)
//             ditemukan = true;
//             break;
//         }
//     }
//     // ubah jadi tipe building
//     Building *tempBuilding = new Building(tempBuildingConfig->getcode(), tempBuildingConfig->getname(), tempBuildingConfig->getprice(), tempBuildingConfig->getmaterials());
//     // pengecekan ditemukannya kode bangunan
//     if (!(ditemukan)) // tidak ada (exception)
//     {
//         std::cout << "Kamu tidak punya resep bangunan tersebut!" << std::endl;
//     }
//     else // prosedur pembangunan
//     {
//         // vektor material bangunan yang ingin dibuat (pengecekan penghapusan bahan pada inventory)
//         std::vector<std::pair<std::string, int>> materials = tempBuildingConfig->getmaterials();
//         // vektor material bangunan yang ingin dibuat juga (pengecekan ketersediaan bahan dari inventory)
//         std::vector<std::pair<std::string, int>> copyMaterials = tempBuildingConfig->getmaterials();
//         // pengecekan ketersediaan jumlah material pada inventory sesuai daftar material bangunan
//         for (int row = 0; row < inventory.getRows(); row++)
//         {
//             for (int col = 0; col < inventory.getCols(); col++)
//             {
//                 for (auto &material : copyMaterials)
//                 {
//                     if (std::get<0>(material) == matriksInventory[row][col]->getname())
//                     {
//                         std::get<1>(material) -= 1;
//                     }
//                 }
//             }
//         }
//         // pengecekan apakah semua material <= 0 (cukup material untuk membangun)
//         for (auto &material : copyMaterials)
//         {
//             if (std::get<1>(material) >= 0)
//             {
//                 cukupMaterial = false;
//             }
//         }
//         // case material dan gulden
//         if (!cukupMaterial || gulden < tempBuilding->getprice()) // tidak cukup material atau gulden
//         {
//             std::cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
//             // pengecekan bahan yang kurang
//             if (gulden < tempBuilding->getprice() && cukupMaterial) // uang tidak cukup (exception)
//             {
//                 std::cout << tempBuilding->getprice() - gulden << " gulden" << std::endl;
//             }
//             else if (gulden >= tempBuilding->getprice() && !cukupMaterial) // tidak cukup material (exception)
//             {
//                 for (auto &material : copyMaterials)
//                 {
//                     if (std::get<1>(material) > 0)
//                     {
//                         std::cout << std::get<1>(material) << " " << std::get<0>(material) << ", ";
//                     }
//                     std::cout << std::endl;
//                 }
//             }
//             else // keduanya tidak cukup (exception)
//             {
//                 std::cout << tempBuilding->getprice() - gulden << " gulden, ";
//                 for (auto &material : copyMaterials)
//                 {
//                     if (std::get<1>(material) > 0)
//                     {
//                         std::cout << std::get<1>(material) << " " << std::get<0>(material) << ", ";
//                     }
//                     std::cout << std::endl;
//                 }
//             }
//         }
//         else // cukup material -> lanjut prosedur pembangunan
//         {
//             // prosedur menghapus material pada inventory yang dibutuhkan untuk membangun
//             for (int row = 0; row < inventory.getRows(); row++)
//             {
//                 for (int col = 0; col < inventory.getCols(); col++)
//                 {
//                     for (auto &material : materials)
//                     {
//                         if (std::get<0>(material) == matriksInventory[row][col]->getname() && std::get<1>(material) > 0)
//                         {
//                             // kebutuhan material dikurangi
//                             std::get<1>(material) -= 1;
//                             // hapus bahannya dari inventory
//                             inventory.deleteValue(row, col);
//                         }
//                     }
//                 }
//             }
//             // masukkan bangunan dalam inventory
//             inventory.setfirstempty(tempBuilding);
//             // print statement
//             std::cout << tempBuildingConfig->getcode() << "berhasil dibangun dan telah menjadi hak milik walikota!" << std::endl;
//         }
//     }
// }

// string Walikota::getRoleType()
// {
//     return "Walikota";
// }

// void Walikota::displayRoleNamesGulden(std::vector<Role *> &daftarPemain)
// {
//     for (const auto &Role : daftarPemain)
//     {
//         std::cout << Role->getUsername() << Role->getGulden() << std::endl;
//     }
// }