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
