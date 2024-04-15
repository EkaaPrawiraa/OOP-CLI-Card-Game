#include "Role/Walikota.hpp"

int Walikota::jumlah = 0;

// seperti role
// Walikota::Walikota(string username, float weight, int uang, int storrows, int storcols) : Role(username, weight, uang, storrows, storcols)
// {
//     jumlah++;
// }

Walikota::Walikota(string username, float weight, int uang, int storrows, int storcols) : Role(username, weight, uang, storrows, storcols)
{
    jumlah++;
}

// panggil constructor pakai ini
Walikota Walikota::conditionalConstructor(string username, float weight, int uang, int storrows, int storcols)
{
    if (Walikota::jumlah == 0)
    {
        std::cout << "Walikota telah berhasil dibuat" << std::endl;
        return Walikota(username, weight, uang, storrows, storcols);
    }
    else // walikota sudah dibuat (exception)
    {
        throw std::runtime_error("Walikota sudah ada!");
    }
}

Walikota::~Walikota()
{
    // vector tidak perlu destructor
    // inventory dihapus di role harusnya
    std::cout << "Walikota dihapus" << std::endl;
}

void Walikota::next()
{
    // standar -> hanya item plant -> implementasi di role?
}

int Walikota::calculate_tax()
{
    // tidak ada tax dari walikota, hanya memungut
    return 0;
}

bool Walikota::compareTaxTuples(std::tuple<Role *, int> a, std::tuple<Role *, int> b)
{
    // menurun secara jumlah
    if (std::get<1>(a) != std::get<1>(b))
    {
        return std::get<1>(a) > std::get<1>(b);
    }
    // nama secara menaik
    return std::get<0>(a)->getUsername() < std::get<0>(b)->getUsername();
}

void Walikota::pungutPajak(std::vector<Role *> daftarPemain)
{
    std::cout << "Cring cring cring..." << std::endl;
    std::cout << "Pajak sudah dipungut!" << std::endl;
    std::cout << std::endl;
    std::cout << "Berikut adalah detil dari pemungutan pajak:" << std::endl;
    int totalPajak = 0;
    // vector pajak untuk pengurutan
    std::vector<std::tuple<Role *, int>> vectorPajak;
    // iterasi setiap pemain
    int pajakTemp = 0;
    for (int i = 0; i < daftarPemain.size(); i++)
    {
        // pengecekan apakah Role berupa walikota
        // tidak pakai exception jika berupa walikota
        if (daftarPemain[i]->getRoleType() != "Walikota")
        {
            // hitung pajak setiap pemain
            pajakTemp = daftarPemain[i]->calculate_tax();
            // testing
            // std::cout << daftarPemain[i]->getUsername() << "pajak " << pajakTemp << std::endl;
            // std::cout << "sisa gulden" << daftarPemain[i]->getGulden() << std::endl;
            // // pengecekan ketersediaan gulden (dalam petani farmer / pungutPajak)
            // if (daftarPemain[i]->getGulden() < pajakTemp)
            // {
            //     pajakTemp = daftarPemain[i]->getGulden();
            // }
            // tambah dalam vector pajak
            vectorPajak.push_back(std::make_tuple(daftarPemain[i], pajakTemp));
            // // aplikasikan pada pemain
            // daftarPemain[i]->setGulden(daftarPemain[i]->getGulden() - pajakTemp);
            // total jumlah pajak

            totalPajak += pajakTemp;
        }
    }
    // pengurutan vector sesuai ketentuan
    std::sort(vectorPajak.begin(), vectorPajak.end(), Walikota::compareTaxTuples);
    // display hasil
    for (int i = 0; i < vectorPajak.size(); i++)
    {
        std::cout << i + 1 << ". " << std::get<0>(vectorPajak[i])->getUsername() << " - "
                  << std::get<0>(vectorPajak[i])->getRoleType()
                  << ": " << std::get<1>(vectorPajak[i]) << " gulden" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Negara mendapatkan pemasukan sebesar " << totalPajak << " gulden." << std::endl;
    std::cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << std::endl;
    // tambah ke uang walikota
    setGulden(getGulden() + totalPajak);
}

bool Walikota::nameExists(std::string name, std::vector<Role *> daftarPemain)
{
    bool found = false;
    int i = 0;
    while (i < daftarPemain.size() && !found)
    {
        if (daftarPemain[i]->getUsername() == name)
        {
            found = true;
            break;
        }
        i++;
    }
    return found;
}

bool Walikota::sortUsername(Role *a, Role *b)
{
    return a->getUsername() < b->getUsername();
}

void Walikota::tambahPemain(std::vector<Role *> &daftarPemain, MiscConfig &configGame)
{
    if (getGulden() < 50) // kurang uang untuk menambah pemain (exception)
    {
        std::cout << "Uang tidak cukup!" << std::endl;
    }
    else
    {
        std::cout << "Masukkan jenis pemain: ";
        std::string jenis;
        std::cin >> jenis;
        if (jenis != "peternak" && jenis != "petani") // jenis tidak valid (exception)
        {
            throw std::runtime_error("jenis tidak valid!");
        }
        else // lanjut
        {
            std::string nama;
            std::cout << "Masukkan nama pemain: ";
            std::cin >> nama;
            if (nameExists(nama, daftarPemain)) // nama sudah ada (exception)
            {
                std::cout << "Nama pemain sudah ada!" << std::endl;
            }
            else
            {
                if (jenis == "peternak")
                {
                    Farmer *tempPeternak = new Farmer(nama, 40, 50, configGame.getStorageRows(), configGame.getStorageCols(), configGame.getFarmRows(), configGame.getFarmCols());
                    daftarPemain.push_back(tempPeternak);
                }
                else if (jenis == "petani")
                {
                    Petani *tempPetani = new Petani(nama, 40, 50, configGame.getStorageRows(), configGame.getStorageCols(), configGame.getLandRows(), configGame.getLandCols());
                    daftarPemain.push_back(tempPetani);
                }
                else{
                    cout<<"Format salah!"<<endl;
                    return;
                }
                // pengurutan urutan pemain (jika ada pemain baru yang ditambahkan)
                std::cout << "Pemain baru ditambahkan!" << std::endl;
                std::cout << "Selamat datang " << nama << " di kota ini!" << std::endl;
                std::sort(daftarPemain.begin(), daftarPemain.end(), Walikota::sortUsername);
                // mengurangi uang dari walikota
                setGulden(getGulden() - 50);
            }
        }
    }
}
void Walikota::bangunBangunan(vector<BuildingRecipeConfig> recipes)
{
    // dapat matrix
    std::map<int, std::map<char, Item *>> matriksInventory = invent.getmatrix();

    // tampilan semua resep bangunan dari config
    std::cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    int i = 1;
    for (const auto &BuildingRecipeConfig : recipes)
    {
        cout << i << ". " << BuildingRecipeConfig.getname() << " ( ";
        for (const auto &material : BuildingRecipeConfig.getmaterials())
        {
            cout << material.first << " " << material.second << " ";
        }
        cout << ")" << endl;
        i++;
    }

    // terima masukan kode bangunan yang ingin dibangun
    std::cout << "Bangunan yang ingin dibangun: ";
    std::string nama;
    std::cin >> nama;
    bool ditemukan = false;
    bool cukupMaterial = true;
    // pencarian kode bangunan pada config
    BuildingRecipeConfig *tempBuildingConfig;
    for (int i = 0; i < recipes.size(); i++)
    {
        if (recipes[i].getname() == nama)
        {
            tempBuildingConfig = new BuildingRecipeConfig(recipes[i]); // cc dari config (tipe config)
            ditemukan = true;
            break;
        }
    }
    // pengecekan ditemukannya kode bangunan
    if (!(ditemukan)) // tidak ada (exception)
    {
        std::cout << "Kamu tidak punya resep bangunan tersebut!" << std::endl;
    }
    else // prosedur pembangunan
    {
        // ubah jadi tipe building
        Item *tempBuilding = new Building(tempBuildingConfig->getcode(), tempBuildingConfig->getname(), tempBuildingConfig->getprice(), tempBuildingConfig->getmaterials());
        // vektor material bangunan yang ingin dibuat (pengecekan penghapusan bahan pada inventory)
        std::vector<std::pair<std::string, int>> materials = tempBuildingConfig->getmaterials();
        // vektor material bangunan yang ingin dibuat juga (pengecekan ketersediaan bahan dari inventory)
        std::vector<std::pair<std::string, int>> copyMaterials = tempBuildingConfig->getmaterials();
        // pengecekan ketersediaan jumlah material pada inventory sesuai daftar material bangunan
        for (int row = 0; row < invent.getRows(); ++row)
        {
            for (char col = 'A'; col < 'A' + invent.getCols(); ++col)
            {
                if (matriksInventory.find(row) != matriksInventory.end() && matriksInventory[row].find(col) != matriksInventory[row].end())
                {
                    for (auto &material : copyMaterials)
                    {
                        if (material.first == matriksInventory[row][col]->getname())
                        {
                            material.second -= 1;
                        }
                    }
                }
            }
        }
        // pengecekan apakah semua material <= 0 (cukup material untuk membangun)
        for (auto &material : copyMaterials)
        {
            if (material.second > 0)
            {
                cukupMaterial = false;
            }
        }
        // case material
        if (!cukupMaterial) // tidak cukup material (exception)
        {
            std::cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << endl;
            // pengecekan bahan yang kurang
            for (auto &material : copyMaterials)
            {
                if (material.second > 0)
                {
                    std::cout << material.second << " " << material.first << " ";
                }
                std::cout << std::endl;
            }
        }
        else // cukup material -> lanjut prosedur pembangunan
        {
            // prosedur menghapus material pada inventory yang dibutuhkan untuk membangun
            for (int row = 0; row < invent.getRows(); ++row)
            {
                for (char col = 'A'; col < 'A' + invent.getCols(); ++col)
                {
                    if (matriksInventory.find(row) != matriksInventory.end() && matriksInventory[row].find(col) != matriksInventory[row].end())
                    {
                        for (auto &material : materials)
                        {
                            if (material.first == matriksInventory[row][col]->getname() && material.second > 0)
                            {
                                // kebutuhan material dikurangi
                                material.second -= 1;
                                // hapus bahannya dari inventory
                                invent.deleteValue(row + 1, col);
                            }
                        }
                    }
                }
            }
            // masukkan bangunan dalam inventory
            invent.setfirstempty(tempBuilding);
            // print statement
            std::cout << tempBuildingConfig->getname() << " berhasil dibangun dan telah menjadi hak milik walikota!" << std::endl;
        }
    }
}

string Walikota::getRoleType()
{
    return "Walikota";
}

void Walikota::displayRoleNamesGulden(std::vector<Role *> &daftarPemain)
{
    for (const auto &Role : daftarPemain)
    {
        std::cout << Role->getUsername() << Role->getGulden() << std::endl;
    }
}

void Walikota::menjual(Store &Toko)
{
    // Validasi tidak bisa menjual bangunan jika bukan walikota
    if (invent.countElement() == 0)
    {
        cout << "Penyimpanan Anda kosong tidak bisa melakukan penjualan" << endl;
        return;
    }

    int totalPrice = 0;

    int quanti;
    invent.display("Penyimpanan");
    cout << "Jumlah barang yang ingin anda jual : ";
    cin >> quanti;
    while (quanti > invent.countElement())
    {
        cout << "Barang yang Anda miliki kurang!" << endl;
        cout << "Jumlah barang yang ingin anda jual : ";
        cin >> quanti;
    }
    for (int i = 1; i <= quanti; i++)
    {
    inputpetak:
        cout << "Petak slot barang ke-" << i << " : ";
        string tok;
        cin.ignore();
        cin >> tok;
        cout << tok << endl;
        std::regex pattern("^[a-zA-Z][0-9]+");
        if ((!std::regex_match(tok, pattern)))
        {
            cout << "Format salah !" << endl;
            goto inputpetak;
        }
        int col = toupper(tok[0]) - 'A';
        int row = std::stoi(tok.substr(1));
        if ((col > invent.getCols() || row > invent.getRows()))
        {
            cout << "Melebihi ukuran penyimpanan!" << endl;
            goto inputpetak;
        }
        if (invent.isemptyslot(row, tok[0]))
        {
            cout << "Petak tersebut kosong!" << endl;
            cout << "Isi ulang!" << endl;
            goto inputpetak;
        }
        else
        {
            // cout << invent.getValue(row, tok[0])->getprice() << endl;
            // Periksa tipe objek dan jualnya
            totalPrice += Toko.sellItem(invent.getValue(row, tok[0]));
            invent.deleteValue(row, tok[0]);
        }
    }
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalPrice << " gulden!" << endl;
}

void Walikota::membeli(Store &Toko)
{
    if (invent.isFull())
    {
        cout << "Penyimpanan Anda Penuh tidak bisa melakukan pembelian" << endl;
    }
    else
    {

        Toko.display();
        cout << "\n\n";
        cout << "Uang Anda : " << this->gulden << endl;
        cout << "Slot penyimpanan tersedia: " << invent.getSize() - invent.countElement() << endl;
        string boughtItem;
        cout << "Kode barang yang ingin dibeli : ";
        cin >> boughtItem;
        int quantity = 0;
        cout << "Kuantitas : ";
        cin >> quantity;
        while (invent.countElement() + quantity > invent.getSize())
        {
            cout << "Penyimpanan anda tidak cukup!" << endl;
            cout << "Sisa penyimpanan : " << invent.getSize() - invent.countElement() << endl;
            cout << "Kuantitas : ";
            cin >> quantity;
        }
        std::pair<int, Item *> passsss = Toko.buyItem(boughtItem, quantity, gulden, getRoleType());
        Item *item = passsss.second;
        int totalpaid = passsss.first;
        cout << item->getname() << endl;
        if (totalpaid > 0)
        {

            this->gulden -= totalpaid;
            cout << endl;
            cout << "Selamat Anda berhasil membeli " << quantity << " " << boughtItem << ". Uang Anda tersisa " << this->gulden << " gulden." << endl;
            cout << endl;
            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
            // belum tau cetak penyimpanan
            invent.display("Penyimpanan");
            // atur cetak penyimpanan
            cout << endl;

            for (int i = 1; i <= quantity; i++)
            {
            inputpetak:
                cout << "Petak slot barang ke-" << i << " : ";
                string tok;
                cin.ignore();
                cin >> tok;
                std::regex pattern("^[a-zA-Z][0-9]+");
                if ((!std::regex_match(tok, pattern)))
                {
                    cout << "Format salah !" << endl;
                    goto inputpetak;
                }
                int col = toupper(tok[0]) - 'A';
                int row = std::stoi(tok.substr(1));
                if ((col > invent.getCols() || row > invent.getRows()))
                {
                    cout << "Melebihi ukuran penyimpanan!" << endl;
                    goto inputpetak;
                }
                if (!invent.isemptyslot(row, tok[0]))
                {
                    cout << "Petak tersebut telah terisi!" << endl;
                    cout << "Isi ulang!" << endl;
                    goto inputpetak;
                }
                else
                {
                    invent.setValue(row, tok[0], item);
                    cout << boughtItem << " berhasil disimpan dalam penyimpanan!" << endl;
                    invent.display("Penyimpanan");
                    cout << item->getclassname();
                }
            }
        }
    }
}
