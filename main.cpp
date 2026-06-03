#include <iostream>
using namespace std;

class Produk {
    private:

        int id;
        string nama;
        int harga;
        int stok;

    public:
<<<<<<< HEAD
        
        Produk (){
            id = 0;
            nama = "";
            harga = 0;
            stok = 0;
        }
        
=======
>>>>>>> dcfcf77684ef268b574979df97e4b2eeeafabe34
        Produk (int id, string nama, int harga, int stok){
            this->id = id;
            this->nama = nama;
            this->harga = harga;
            this->stok = stok;
        }

        void setId(int id){
            this->id = id;
        }

        void setNama(string nama){
            this->nama= nama;
        }

        void setharga(int harga){
            this->harga = harga;
        }

        void setStok(int stok){
            this->stok = stok;
        }

        int getId(){
            return id;
        }

        string getNama(){
            return nama;
        }

        int getHarga(){
            return harga;
        }

        int getStok(){
            return stok;
        }

<<<<<<< HEAD
};

struct CartNode
{
    Produk *produk;
    int qty;
    CartNode *next;
};
struct OrderNode
{
    int orderId;
    string detail;
    int total;
    OrderNode *next;
};

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
             << "Nama: " << head->produk->getNama()
             << "Qty: " << head->qty
             << "Subtotal: " << subtotal << endl;
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

int main (){


    cout << "Selamat datang di Toko Sembako!" << endl;
    cout << "         Masuk Sebagai         " << endl;
    cout << "1. Admin" << endl;
    cout << "2. Pembeli" << endl;
    cout << "Pilih peran: ";
    int peran;
    cin >> peran;


    if (peran == 1) {
        cout << "Anda masuk sebagai Admin" << endl;
    do {
    int pilihan;
        cout << "----Menu----" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk" << endl;
        cout << "4. Proses pesanan" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Tambah Produk" << endl;
                break;
            case 2:
                cout << "Tampilkan Semua Produk" << endl;
                break;
            case 3:
                cout << "Cari Produk" << endl;
                break;
            case 4:
                cout << "Proses pesanan" << endl;
                break;
            case 0:
                cout << "Kembali" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (true);

    } else if (peran == 2) {
        cout << "Anda masuk sebagai Pembeli" << endl;
        do {

    int pilihan;
        cout << "----Menu----" << endl;
        cout << "1. Tampilkan Semua Produk" << endl;
        cout << "2. Cari Produk" << endl;
        cout << "3. Checkout Produk" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Tampilkan Semua Produk" << endl;
                break;
            case 2:
                cout << "Cari Produk" << endl;
                break;
            case 3:
                cout << "Checkout Produk" << endl;
                break;
            case 0:
                cout << "Kembali" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (true);
    
    } else if (peran == 0) {
        cout << "Terima kasih telah menggunakan aplikasi Toko Sembako!" << endl;
        return 0;
    }else {
        cout << "Pilihan tidak valid" << endl;
    }

    return 0;
}


=======

        void tampilkan(){
            cout << "Id produk: " << getNama() << endl;
        }
};





int main (){

    int pilihan;

    do {
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. keluar" << endl;
    cout << "Pilih (angka): ";
    cin >> pilihan;
    cout << endl;

    if (!(cin >> pilihan)){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Input harus angka!\n" << endl;
        continue;
    }

    switch (pilihan)
    {
    case 1:

        

        break;
    case 2:

        break;

    default:
        continue;
        break;
    }



}while (pilihan !=3);

    return 0;
}
>>>>>>> dcfcf77684ef268b574979df97e4b2eeeafabe34
