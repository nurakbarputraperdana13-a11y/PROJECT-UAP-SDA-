#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

void tambahProduk(Produk*daftarProduk[], int&jumlahProduk, int kapasitas){
    if(jumlahProduk >= kapasitas){
        cout << "Daftar produk penuh. Tidak bisa menambahkan produkmbaru." << endl;
        return;
    }

    cout << "\nTambah Produk Baru" << endl;
    cout << "1. Makanan" << endl;
    cout << "2. Minuman" << endl;
    cout << "Pilih kategori: ";
    int kategori;
    cin >> kategori;

    int id, harga stok;
    string nama;

    cout << "ID produk: ";
    cin >> id;
    cin.ignore(numeric_lim its<streamsize>::max()'\n');
    cout << "Nama produk: ";
    getline(cin, nama);
    cout << "Harga produk: ";
    cin >> harga;
    cout << "Stok produk: ";
    cin >> stok;

    if (kategori == 1){
        daftarProduk[jumlahProduk++]= new Makanan(id, nama, harga, stok);
    }
    else if (kategori == 2){
        daftarProduk[jumlahProduk++] = new Minuman(id, nama, harga, stok);
    }
    else{
        cout << "Kategori tidak valid, Produk tidak ditambahka." << endl;
        return;
    }
    cout << "Produk berhasil ditambahkan." << endl;
}

void hapusProduk(Produk*daftarProduk[], int&jumlahProduk){
    if(jumlahProduk == 0){
        cout << "\nTidak ada produk untuk dihapus." << endl;
        return;
    }

    cout <<"\nHapus Produk" << endl;
    cout <<"Masukkan ID produk yang akan dihapus: ";
    int id;
    cin >> id;

    int index = -1;
    for(int i = 0; i < jumlahProduk;i++){
        if(daftarProduk[i]->getId()==id){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "Produk dengan ID " << id << "tidak ditemukan." << endl;
        return;
    }

    delete daftarProduk[index];
    for(int i = index; i < jumlahProduk-1;i++){
        daftarProduk[i]= daftarProduk[i+1];
    }
    jumlahProduk--;
    cout << "Produk berhasil dihapus. " << endl;
}

string toLower(const string &text){
    string lower = text;
    for (char &ch : lower)
    ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    return lower;
}
\\tambah