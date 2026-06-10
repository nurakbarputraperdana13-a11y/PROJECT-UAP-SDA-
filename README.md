# PROJECT-UAP-SDA-
# 🛒 Sistem Manajemen Toko Online Sederhana (C++)

## 📖 Deskripsi

Program ini merupakan aplikasi manajemen toko online sederhana berbasis C++ yang menyediakan dua peran pengguna, yaitu **Admin** dan **Pembeli**. Program ini menerapkan beberapa struktur data untuk mengelola produk, keranjang belanja, dan antrian pesanan.

---

## ✨ Fitur Utama

### 👨‍💼 Admin

* ➕ Menambahkan produk baru.
* ❌ Menghapus produk.
* 📋 Menampilkan seluruh produk.
* 🔍 Mencari produk.
* 📦 Melihat dan memproses antrian pesanan.

### 🛍️ Pembeli

* 📋 Melihat daftar produk.
* 🔍 Mencari produk.
* 🛒 Menambahkan produk ke keranjang.
* 💳 Checkout produk.
* 📦 Membuat pesanan yang masuk ke antrian.

---

## 🏗️ Struktur Data yang Digunakan

### 📊 1. Array 2 Dimensi

Digunakan untuk menyimpan dan mengelola data produk.

**Fungsi:**

* ➕ Tambah produk
* ❌ Hapus produk
* 📋 Tampilkan produk

**Kelebihan:**

* ⚡ Akses data cepat menggunakan indeks.
* 🧩 Mudah diimplementasikan untuk jumlah data yang tidak terlalu besar.

---

### 🔎 2. Searching (Pencarian)

Digunakan untuk mencari produk berdasarkan nama.

**Fungsi:**

* Mempermudah admin dan pembeli menemukan produk yang diinginkan.

**Metode:**

* 🔍 Sequential Search (Linear Search)

---

### 🔗 3. Linked List

Digunakan untuk implementasi keranjang belanja (Shopping Cart).

**Fungsi:**

* 🛒 Menambahkan produk ke keranjang.
* 📦 Menyimpan item secara dinamis.
* 🗑️ Menghapus seluruh isi keranjang setelah checkout atau logout.

**Keunggulan:**

* 📈 Ukuran fleksibel sesuai jumlah barang yang dipilih.

---

### 📬 4. Queue (Antrian)

Digunakan untuk mengelola pesanan pelanggan.

**Fungsi:**

* 📦 Menyimpan pesanan hasil checkout.
* ⏳ Memproses pesanan berdasarkan urutan kedatangan (FIFO).

**Operasi Queue:**

* ➕ Enqueue → Menambahkan pesanan ke antrian.
* ➖ Dequeue → Memproses pesanan terdepan.
* 📋 Display Queue → Menampilkan seluruh antrian pesanan.

---

## 🔄 Alur Program

### 🔐 Login

Pengguna memilih peran:

1. 👨‍💼 Admin
2. 🛍️ Pembeli

### 👨‍💼 Admin

```text
Tambah Produk
     ↓
Hapus Produk
     ↓
Lihat Produk
     ↓
Cari Produk
     ↓
Kelola Antrian Pesanan
```

### 🛍️ Pembeli

```text
Lihat Produk
     ↓
Cari Produk
     ↓
Tambah ke Keranjang
     ↓
Checkout
     ↓
Masuk ke Antrian Pesanan
```

---

## 🧠 Konsep Struktur Data yang Diterapkan

| Fitur                | Struktur Data   |
| -------------------- | --------------- |
| 📦 Data Produk       | Array 2 Dimensi |
| 🔍 Cari Produk       | Searching       |
| 🛒 Keranjang Belanja | Linked List     |
| 📬 Antrian Pesanan   | Queue           |

---

## 👥 Pembagian Tugas Kelompok

| Nama                       | Tugas                                                |
| -------------------------- | ---------------------------------------------------- |
| 👩 Siti Nurmawati          | ➕ Tambah Produk dan ❌ Hapus Produk (Array 2 Dimensi) |
| 👨 Galang                  | 🔍 Pencarian Produk (Searching)                      |
| 👨 Rismansyah              | 🛒 Linked List untuk Keranjang Belanja dan Checkout  |
| 👨 Nur Akbar Putra Perdana | 📬 Queue untuk Antrian Pesanan                       |

---

## 🚀 Cara Menjalankan Program

### Compile

```bash
g++ main.cpp -o toko
```

### Jalankan

```bash
./toko
```

---

## 🎯 Tujuan Proyek

Proyek ini dibuat untuk mempelajari implementasi berbagai struktur data dasar dalam bahasa C++, yaitu:
* 
* 📊 Array 2 Dimensi
* 🔍 Searching
* 🔗 Linked List
* 📬 Queue
* 👉 Pointer
* 🏗️ Struct 

melalui studi kasus sistem toko online sederhana.

---

## 👨‍🎓 Mata Kuliah

**Struktur Data**

## 🏫 Program Studi

**Manajemen Informatika**

## 📜 Lisensi

**Kelompok 1**

Proyek ini dibuat untuk keperluan pembelajaran dan tugas akademik.


