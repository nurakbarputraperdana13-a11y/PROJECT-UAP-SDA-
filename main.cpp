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