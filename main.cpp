#include <iostream>
using namespace std;

class Produk {
    private:

        int id;
        string nama;
        int harga;
        int stok;

    public:
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


        void tampilkan(){
            cout << "Id produk: " << getNama() << endl;
        }
};








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