#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

class Produk
{
private:
    int id;
    string nama;
    int harga;
    int stok;

public:
    Produk() : id(0), nama(""), harga(0), stok(0) {}

    Produk(int id, string nama, int harga, int stok)
        : id(id), nama(nama), harga(harga), stok(stok) {}

    virtual ~Produk() {}

    void setId(int id)
    {
        this->id = id;
    }

    void setNama(const string &nama)
    {
        this->nama = nama;
    }

    void setHarga(int harga)
    {
        this->harga = harga;
    }

    void setStok(int stok)
    {
        this->stok = stok;
    }

    int getId() const
    {
        return id;
    }

    string getNama() const
    {
        return nama;
    }

    int getHarga() const
    {
        return harga;
    }

    int getStok() const
    {
        return stok;
    }

    virtual string getKategori() const
    {
        return "Produk";
    }
};

class Makanan : public Produk
{
public:
    Makanan(int id, string nama, int harga, int stok)
        : Produk(id, nama, harga, stok) {}

    string getKategori() const override
    {
        return "Makanan";
    }
};

class Minuman : public Produk
{
public:
    Minuman(int id, string nama, int harga, int stok)
        : Produk(id, nama, harga, stok) {}

    string getKategori() const override
    {
        return "Minuman";
    }
};

void cariProduk(Produk *daftarProduk[], int jumlahProduk){
    if(jumlahProduk == 0){
        cout << "\nTidak ada produk untuk dicari." << endl;
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nCari produk" << endl;
    cout << "Masukkan nama produk atau kata kunci: ";
    string keyword;
    getline(cin, keyword);

    if(keyword.empty()) 
    {
        cout << "Kata kunci tidak boleh kosong." << endl;
        return;
    }

    string keywordLower = toLower(keyword);
    bool ditemukan = false;

    for (int i = 0; i < jumlahProduk; i++) 
    {
        string namaLower = toLower(daftarProduk[i]->getNama());
        if (namaLower.find(keywordLower) != string::npos) 
        {
            if (!ditemukan)
            {
                cout << "\nHasil pencarian: \n";
                ditemukan = true;
            }
            cout << "ID: " << daftarProduk[i]->getId() << endl;
            cout << "Nama: " << daftarProduk[i]->getNama() << endl;
            cout << "Harga: " << daftarProduk[i]->getHarga() << endl;
            cout << "Stok: " << daftarProduk[i]->getStok() << endl
        };
    }
    if (!ditemukan)
    {
        cout << "\nProduk tidak ditemukan." << endl;
    }
}