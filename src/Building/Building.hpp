#include <string>
using namespace std;

class Building{

    private:
    string nama;
    string kode;
    int harga;

    public:
    string getNama() const;
    string getKode() const;
    int getHarga()  const;
    void setNama(string) ;
    void setKode(string);
    void setHarga(int );

};