# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Kedua)</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori


### A. Materi Praktikum <br/>
...
#### 1. Double Linked List (DDL)
#### 2. Searching DDL
#### 2. Manipulasi data DDL


### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Guided 1
listMakanan.h
```C++
```

listMakanan.cpp
```C++
```

main.cpp
```C++
```
Kode di atas merupakan 

### 2. Guided 2
listMakanan.h
```C++
```

listMakanan.cpp
```C++
```

main.cpp
```C++
```
Kode di atas merupakan 

## Unguided 
### 1. soal unguided 1
Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:
```
Type infotype : kendaraan <
    nopol : string
    warna : string
    thnBuat : integer
>
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next :address
    prev : address
>
Type List <
    First : address
    Last : address
>
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertLast(input/output L : List,input P : address )
```
Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.

### Jawaban
Doublylist.h
```C++
```

Doublylist.cpp
```C++
```

main.h
```C++
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-6/Laprak-modul-6/assets/output-1.png)
Fungsi program di atas adalah untuk menyimpan, memeriksa, dan menampilkan data kendaraan menggunakan struktur data Doubly Linked List. Program memungkinkan pengguna memasukkan beberapa data kendaraan berupa nomor polisi, warna, dan tahun pembuatan. Setiap data yang dimasukkan akan diperiksa terlebih dahulu agar nomor polisi tidak duplikat. Jika belum terdaftar, data tersebut ditambahkan ke dalam list di bagian akhir (insertLast). Setelah semua data dimasukkan, program akan menampilkan seluruh data kendaraan yang tersimpan di list secara mundur (dari belakang ke depan).

### 2. soal unguided 2
Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.
fungsi findElm( L : List, x : infotype ) : address

### Jawaban
Doublylist.h
```C++
```

Doublylist.cpp
```C++
```

main.cpp
```C++
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-6/Laprak-modul-6/assets/output-2.png)
Melanjutkan kode pada Unguided 1,
Fungsi program di atas adalah untuk menyimpan dan mencari data kendaraan menggunakan struktur data Doubly Linked List. Program memungkinkan pengguna memasukkan beberapa data kendaraan berupa nomor polisi, warna, dan tahun pembuatan, lalu menyimpannya ke dalam list. Sebelum data dimasukkan, program akan memeriksa apakah nomor polisi sudah terdaftar agar tidak ada duplikasi. Setelah semua data disimpan, program menampilkan seluruh isi list dari belakang ke depan. Selain itu, pengguna juga dapat mencari data kendaraan berdasarkan nomor polisi melalui fungsi findElm, yang akan menampilkan detail kendaraan jika ditemukan, atau memberi pesan “Data tidak ditemukan” jika tidak ada di dalam list.

### 3. soal unguided 3
Hapus elemen dengan nomor polisi D003 dengan procedure delete.
    - procedure deleteFirst( input/output L : List, P : address )
    - procedure deleteLast( input/output L : List, P : address )
    - procedure deleteAfter( input Prec : address, input/output P : address )

### Jawaban
Doublylist.h
```C++
```

Doublylist.cpp
```C++
```

main.cpp
```C++
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-6/Laprak-modul-6/assets/output-3.png)
Melanjutkan kode unguided 1 dan 2
Fungsi program di atas adalah untuk mengelola data kendaraan menggunakan struktur data Doubly Linked List. Program memungkinkan pengguna untuk menambahkan, mencari, dan menghapus data kendaraan yang berisi nomor polisi, warna, dan tahun pembuatan. Saat pengguna memasukkan data, program akan memeriksa apakah nomor polisi sudah terdaftar agar tidak ada duplikasi, lalu data disimpan di akhir list. Pengguna juga dapat mencari kendaraan berdasarkan nomor polisi menggunakan fungsi findElm, dan menghapus data kendaraan dari list menggunakan fungsi deleteFirst, deleteLast, atau deleteAfter, tergantung posisi data yang akan dihapus (awal, akhir, atau tengah). Setelah setiap operasi, program menampilkan isi list kendaraan yang tersisa.

## Kesimpulan
Berdasarkan hasil praktikum yang berfokus pada penerapan Doubly Linked List (DLL), dapat disimpulkan bahwa struktur data ini memiliki fleksibilitas dan efisiensi tinggi dalam pengelolaan data dinamis. Setiap node pada DLL memiliki dua pointer, yaitu next dan prev, yang memungkinkan traversal dua arah (maju dan mundur). Hal ini memberikan keuntungan signifikan dibandingkan Singly Linked List, terutama dalam operasi penyisipan, penghapusan, dan pembaruan data di posisi tertentu, tanpa harus menelusuri seluruh list dari awal.[1]

Implementasi program menggunakan bahasa C++ pada praktikum ini membuktikan bahwa konsep Abstract Data Type (ADT) dapat diterapkan secara modular dan efisien.[1] File listMakanan.h berfungsi untuk mendefinisikan struktur dan deklarasi fungsi, listMakanan.cpp untuk implementasi logika, dan main.cpp untuk menjalankan alur program. Operasi seperti insert, update, search, dan delete berhasil diimplementasikan dengan baik, menunjukkan bagaimana DLL dapat digunakan dalam pengelolaan data yang membutuhkan akses fleksibel.[3]

Selain itu, penerapan fungsi-fungsi seperti insertAfter, insertBefore, deleteByName, dan findByMinRating memperlihatkan keunggulan DLL dalam menangani data dengan berbagai kebutuhan manipulasi. Dengan struktur dua arah, program mampu mengelola data makanan secara efisien, baik dari sisi memori maupun kompleksitas waktu operasi.

## Referensi
[1] Wijoyo, A., Prasetiyo, A. R., Salsabila, A. A., Nife, K., Murni, & Nadapdap, P. B. (2024). Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1244-1246. Diakses dari https://jurnalmahasiswa.com/index.php/jriin/article/view/1060 <br/>
[2] Wijoyo, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., Putra, R. T. S., Arifin, T., & Farhan, A. (2024). Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1329-1331.<br/>
[3]Wisesty, U. N., Nurrahmi, H., Yunanto, P. E., Rismala, R., & Sthevanie, F. (2025). STRUKTUR DATA MENGGUNAKAN C++. PENERBIT KBM INDONESIA.


