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

void tampilkanProduk(Produk *daftarProduk[], int jumlahProduk)
{
    cout << "\nDaftar Produk:\n";
    if (jumlahProduk == 0)
    {
        cout << "Tidak ada produk tersedia." << endl;
        return;
    }

    for (int i = 0; i < jumlahProduk; i++)
    {
        Produk *produk = daftarProduk[i];
        cout << "ID: " << produk->getId()
             << " | Nama: " << produk->getNama()
             << " | Kategori: " << produk->getKategori()
             << " | Harga: " << produk->getHarga()
             << " | Stok: " << produk->getStok() << endl;
    }
}

void tambahProduk(Produk *daftarProduk[], int &jumlahProduk, int kapasitas)
{
    if (jumlahProduk >= kapasitas)
    {
        cout << "Daftar produk penuh. Tidak bisa menambahkan produk baru." << endl;
        return;
    }

    cout << "\nTambah Produk Baru" << endl;
    cout << "1. Makanan" << endl;
    cout << "2. Minuman" << endl;
    cout << "Pilih kategori: ";
    int kategori;
    cin >> kategori;

    int id, harga, stok;
    string nama;

    cout << "ID produk: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nama produk: ";
    getline(cin, nama);
    cout << "Harga produk: ";
    cin >> harga;
    cout << "Stok produk: ";
    cin >> stok;

    if (kategori == 1)
    {
        daftarProduk[jumlahProduk++] = new Makanan(id, nama, harga, stok);
    }
    else if (kategori == 2)
    {
        daftarProduk[jumlahProduk++] = new Minuman(id, nama, harga, stok);
    }
    else
    {
        cout << "Kategori tidak valid. Produk tidak ditambahkan." << endl;
        return;
    }

    cout << "Produk berhasil ditambahkan." << endl;
}

void hapusProduk(Produk *daftarProduk[], int &jumlahProduk)
{
    if (jumlahProduk == 0)
    {
        cout << "\nTidak ada produk untuk dihapus." << endl;
        return;
    }

    cout << "\nHapus Produk" << endl;
    cout << "Masukkan ID produk yang akan dihapus: ";
    int id;
    cin >> id;

    int index = -1;
    for (int i = 0; i < jumlahProduk; i++)
    {
        if (daftarProduk[i]->getId() == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
        return;
    }

    delete daftarProduk[index];
    for (int i = index; i < jumlahProduk - 1; i++)
    {
        daftarProduk[i] = daftarProduk[i + 1];
    }
    jumlahProduk--;
    cout << "Produk berhasil dihapus." << endl;
}

string toLower(const string &text)
{
    string lower = text;
    for (char &ch : lower)
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    return lower;
}

void cariProduk(Produk *daftarProduk[], int jumlahProduk)
{
    if (jumlahProduk == 0)
    {
        cout << "\nTidak ada produk untuk dicari." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nCari Produk" << endl;
    cout << "Masukkan nama produk atau kata kunci: ";
    string keyword;
    getline(cin, keyword);

    if (keyword.empty())
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
                cout << "\nHasil pencarian:\n";
                ditemukan = true;
            }
            cout << "ID: " << daftarProduk[i]->getId()
                 << " | Nama: " << daftarProduk[i]->getNama()
                 << " | Kategori: " << daftarProduk[i]->getKategori()
                 << " | Harga: " << daftarProduk[i]->getHarga()
                 << " | Stok: " << daftarProduk[i]->getStok() << endl;
        }
    }

    if (!ditemukan)
    {
        cout << "Produk tidak ditemukan." << endl;
    }
}

struct CartNode
{
    Produk *produk;
    int qty;
    CartNode *next;
};

Produk *cariProdukById(Produk *daftarProduk[], int jumlahProduk, int id)
{
    for (int i = 0; i < jumlahProduk; i++)
    {
        if (daftarProduk[i]->getId() == id)
        {
            return daftarProduk[i];
        }
    }
    return nullptr;
}

CartNode *cariItemKeranjang(CartNode *head, int id)
{
    while (head != nullptr)
    {
        if (head->produk->getId() == id)
            return head;
        head = head->next;
    }
    return nullptr;
}

void tampilkanKeranjang(CartNode *head)
{
    cout << "\nKeranjang Belanja:\n";
    if (head == nullptr)
    {
        cout << "Keranjang kosong." << endl;
        return;
    }

    int total = 0;
    while (head != nullptr)
    {
        int subtotal = head->produk->getHarga() * head->qty;
        cout << "ID: " << head->produk->getId()
             << " | Nama: " << head->produk->getNama()
             << " | Jumlah: " << head->qty
             << " | Harga satuan: " << head->produk->getHarga()
             << " | Subtotal: " << subtotal << endl;
        total += subtotal;
        head = head->next;
    }
    cout << "Total bayar: " << total << endl;
}

void tambahKeKeranjang(CartNode *&head, Produk *daftarProduk[], int jumlahProduk)
{
    if (jumlahProduk == 0)
    {
        cout << "\nTidak ada produk yang tersedia untuk ditambahkan." << endl;
        return;
    }

    cout << "\nMasukkan ke Keranjang" << endl;
    cout << "ID produk: ";
    int id;
    cin >> id;

    Produk *produk = cariProdukById(daftarProduk, jumlahProduk, id);
    if (produk == nullptr)
    {
        cout << "Produk dengan ID tersebut tidak ditemukan." << endl;
        return;
    }

    cout << "Jumlah yang dibeli: ";
    int qty;
    cin >> qty;
    if (qty <= 0)
    {
        cout << "Jumlah harus lebih dari nol." << endl;
        return;
    }

    if (qty > produk->getStok())
    {
        cout << "Stok tidak mencukupi. Stok tersedia: " << produk->getStok() << endl;
        return;
    }

    CartNode *item = cariItemKeranjang(head, id);
    if (item != nullptr)
    {
        item->qty += qty;
    }
    else
    {
        CartNode *baru = new CartNode{produk, qty, nullptr};
        if (head == nullptr)
        {
            head = baru;
        }
        else
        {
            CartNode *tail = head;
            while (tail->next != nullptr)
                tail = tail->next;
            tail->next = baru;
        }
    }

    cout << "Produk berhasil ditambahkan ke keranjang." << endl;
}

struct OrderNode
{
    int orderId;
    string detail;
    int total;
    OrderNode *next;
};

void enqueuePesanan(OrderNode *&head, OrderNode *&tail, int orderId, const string &detail, int total)
{
    OrderNode *baru = new OrderNode{orderId, detail, total, nullptr};
    if (head == nullptr)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

bool dequeuePesanan(OrderNode *&head, OrderNode *&tail, OrderNode *&pesanan)
{
    if (head == nullptr)
        return false;

    pesanan = head;
    head = head->next;
    if (head == nullptr)
        tail = nullptr;
    pesanan->next = nullptr;
    return true;
}

void tampilkanAntrianPesanan(OrderNode *head)
{
    cout << "\nAntrian Pesanan:\n";
    if (head == nullptr)
    {
        cout << "Tidak ada pesanan dalam antrian." << endl;
        return;
    }

    while (head != nullptr)
    {
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

void checkoutKeranjang(CartNode *&head, OrderNode *&queueHead, OrderNode *&queueTail, int &nextOrderId)
{
    if (head == nullptr)
    {
        cout << "\nKeranjang masih kosong." << endl;
        return;
    }

    CartNode *node = head;
    while (node != nullptr)
    {
        if (node->qty > node->produk->getStok())
        {
            cout << "Stok tidak cukup untuk produk " << node->produk->getNama() << ". Checkout dibatalkan." << endl;
            return;
        }
        node = node->next;
    }

    cout << "\nCheckout Keranjang:\n";
    int total = 0;
    string detail;
    while (head != nullptr)
    {
        int subtotal = head->produk->getHarga() * head->qty;
        detail += head->produk->getNama() + "(x" + to_string(head->qty) + ") ";
        cout << "ID: " << head->produk->getId()
             << " | Nama: " << head->produk->getNama()
             << " | Qty: " << head->qty
             << " | Subtotal: " << subtotal << endl;
        total += subtotal;
        int baruStok = head->produk->getStok() - head->qty;
        head->produk->setStok(baruStok);

        CartNode *hapus = head;
        head = head->next;
        delete hapus;
    }

    enqueuePesanan(queueHead, queueTail, nextOrderId++, detail, total);
    cout << "Total pembayaran: " << total << endl;
    cout << "Pesanan telah dimasukkan ke antrian." << endl;
}

void clearCart(CartNode *&head)
{
    while (head != nullptr)
    {
        CartNode *hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main()
{
    const int kapasitasProduk = 100;
    Produk *daftarProduk[kapasitasProduk];
    int jumlahProduk = 0;
    CartNode *cartHead = nullptr;
    OrderNode *queueHead = nullptr;
    OrderNode *queueTail = nullptr;
    int nextOrderId = 1;
    bool running = true;

    daftarProduk[jumlahProduk++] = new Makanan(1, "Beras", 20000, 10);
    daftarProduk[jumlahProduk++] = new Makanan(2, "Sarden", 15000, 15);
    daftarProduk[jumlahProduk++] = new Minuman(3, "Torabika", 5000, 25);
    daftarProduk[jumlahProduk++] = new Minuman(4, "Kopi Tubruk", 7000, 20);

    while (running)
    {
        cout << "Selamat datang di Aplikasi Toko Online" << endl;
        cout << "         Masuk Sebagai         " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pembeli" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih peran: ";
        int peran;
        cin >> peran;

        if (peran == 1)
        {
            cout << "Anda masuk sebagai Admin" << endl;
            bool inAdmin = true;
            while (inAdmin)
            {
                int pilihan;
                cout << "----Menu Admin----" << endl;
                cout << "1. Tambah Produk" << endl;
                cout << "2. Hapus Produk" << endl;
                cout << "3. Tampilkan Semua Produk" << endl;
                cout << "4. Cari Produk" << endl;
                cout << "5. Antrian Pesanan" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                switch (pilihan)
                {
                case 1:
                    tambahProduk(daftarProduk, jumlahProduk, kapasitasProduk);
                    break;
                case 2:
                    hapusProduk(daftarProduk, jumlahProduk);
                    break;
                case 3:
                    tampilkanProduk(daftarProduk, jumlahProduk);
                    break;
                case 4:
                    cariProduk(daftarProduk, jumlahProduk);
                    break;
                case 5:
                    cout << "Antrian Pesanan" << endl;
                    tampilkanAntrianPesanan(queueHead);
                    if (queueHead != nullptr)
                    {
                        cout << "Proses pesanan terdepan? (1=ya, 0=tidak): ";
                        int proses;
                        cin >> proses;
                        if (proses == 1)
                        {
                            OrderNode *pesanan = nullptr;
                            if (dequeuePesanan(queueHead, queueTail, pesanan))
                            {
                                cout << "Pesanan #" << pesanan->orderId << " diproses. Total: " << pesanan->total << " | " << pesanan->detail << endl;
                                delete pesanan;
                            }
                        }
                    }
                    break;
                case 0:
                    cout << "Kembali ke menu login" << endl;
                    clearCart(cartHead);
                    inAdmin = false;
                    break;
                default:
                    cout << "Pilihan tidak valid" << endl;
                }
            }
        }
        else if (peran == 2)
        {
            cout << "Anda masuk sebagai Pembeli" << endl;
            bool inPembeli = true;
            while (inPembeli)
            {
                int pilihan;
                cout << "----Menu Pembeli----" << endl;
                cout << "1. Tampilkan Semua Produk" << endl;
                cout << "2. Cari Produk" << endl;
                cout << "3. Masukan ke keranjang" << endl;
                cout << "4. Checkout Produk" << endl;
                cout << "5. Kembali" << endl;
                cout << "0. Keluar" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                switch (pilihan)
                {
                case 1:
                    tampilkanProduk(daftarProduk, jumlahProduk);
                    break;
                case 2:
                    cariProduk(daftarProduk, jumlahProduk);
                    break;
                case 3:
                    tambahKeKeranjang(cartHead, daftarProduk, jumlahProduk);
                    break;
                case 4:
                    checkoutKeranjang(cartHead, queueHead, queueTail, nextOrderId);
                    break;
                case 5:
                    cout << "Kembali ke menu login" << endl;
                    clearCart(cartHead);
                    inPembeli = false;
                    break;
                case 0:
                    cout << "Keluar" << endl;
                    clearCart(cartHead);
                    clearQueue(queueHead, queueTail);
                    running = false;
                    inPembeli = false;
                    break;
                default:
                    cout << "Pilihan tidak valid" << endl;
                }
            }
        }
        else if (peran == 0)
        {
            cout << "Terima kasih telah menggunakan aplikasi Toko Sembako!" << endl;
            running = false;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }

    clearCart(cartHead);
    clearQueue(queueHead, queueTail);
    for (int i = 0; i < jumlahProduk; i++)
    {
        delete daftarProduk[i];
    }
    return 0;
}
