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

struct OrderNode{
    int orderId;
    string detail;
    int total;
    OrderNode* next;
};

void enqueuePesanan(OrderNode *&head, OrderNode *tail, int orderId, const string &detail, int total){
    OrderNode *baru = new OrderNode(orderId, detail, total, nullptr);
    if (head == nullptr){
        head = baru;
        tail = baru;
    }else {
        tail ->next;
        tail = baru;
    }
}

bool dequeuePesanan(OrderNode *&head, OrderNode&tail){
    if (head == nullptr)
    return false;

    pesanan = head;
    head = head->next;
    if (head == nullptr)
        tail ==nullptr;
    pesanan->next = nullptr;
    return true;
}

void tampilkanAntrianPesanan(OrderNode *head){
    cout << "\nAntrian Pesanan";
    if (head == nullptr){
        cout << "Tidak ada pesanan dalam antrian." << endl;
        return;
    }

    while (head != nullptr) {
        cout << "Order #" << head->orderId
             << " | Total: " << head->total
             << " | Detail: " << head->detail << endl;
        head = head->next;
    }
}

void clearQueue(OrderNode *&head, OrderNode *&tail)
{
    while (head != nullptr)
    {
        OrderNode *hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = nullptr;
}