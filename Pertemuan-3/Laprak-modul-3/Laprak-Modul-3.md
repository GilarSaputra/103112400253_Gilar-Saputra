# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Abstract Data Type (ADT) merupakan suatu model matematis untuk tipe data, yang didefinisikan secara konseptual berdasarkan perilaku (semantics) tipe data tersebut dari sudut pandang pengguna, tanpa menspesifikasikan detail implementasinya (prinsip abstraksi dan enkapsulasi)[2]. Sesuai dengan materi praktikum, ADT terdiri dari TYPE dan sekumpulan PRIMITIF (operasi dasar) yang berlaku pada tipe tersebut, yang juga mencakup invarian dan aksioma. Primitif dikelompokkan menjadi: Konstruktor/Kreator (pemebentuk nilai), Selector (pengakses komponen), Prosedur pengubah nilai, Tipe validator, Destruktor/Dealokator, Baca/Tulis (untuk I/O), Operator relasional, Aritmatika, dan Konversi. Implementasi ADT secara umum sering dipisahkan ke dalam dua modul utama: file Definisi/Spesifikasi Type dan Primitif (.h), yang memuat deklarasi struktur data dan signature operasi, serta file Body/Realisasi Primitif (.c/.cpp), yang memuat kode program untuk implementasi operasi tersebut. Konsep ADT ini menjadi fundamental dalam ilmu komputer, digunakan dalam perancangan dan analisis algoritma, struktur data (seperti Stack atau Queue), serta penting dalam metodologi pemrograman berorientasi objek (Object-Oriented Programming) untuk mencapai modularitas, dan mendukung reusabilitas kode, seperti yang dijelaskan dalam berbagai jurnal dan literatur akademik[1].


### A. Materi Praktikum <br/>
...
### 1. Struct
### 2. ADT

### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Struct

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(Mahasiswa &m) {
    cout << "Masukan nama mahasiswa :" ;
    cin >> m.nama;
    cout << "Masukan nilai 1 :";
    cin >> m.nilai1;   
    cout << "Masukan nilai 2 :";
    cin >> m.nilai2;
}

float rata2(Mahasiswa m) {
    return((m.nilai1 + m.nilai2)/2);
}

int main() {
    Mahasiswa mhs;  
    inputMhs(mhs);
    cout << "Rata-rata : " << rata2(mhs);
}
```
Kode di atas adalah kode yang berfungsi untuk menghitung nilai rata rata yang di peroleh dari inputan user berupa nama, nilai1, dan nilai 2. program akan mengeksekusi fungsi rata2 untuk menghitung rata rata dari (nilai1 + nilai2)/2.

### 2. ADT 3 file

```C++
//KODE <pelajaran.h> Start 
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodePel);

void tampil_pelajaran(pelajaran pel);

#endif
//KODE <pelajaran.h> End 

//KODE <pelajaran.cpp> Start
#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran: " << pel.namaMapel << endl;
    cout << "nilai: " << pel.kodeMapel << endl;
}
//KODE <pelajaran.cpp> End

//KODE <main.cpp> Start
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
//KODE <main.cpp> End

```
Kode di atas adalah kode yang berfungsi sebagai bagaimana ADT memisahkan apa yang dilakukan oleh tipe data (didefinisikan di .h) dari bagaimana implementasinya (dikerjakan di .cpp), untuk mengahasilkan output nama matakuliah beserta kodenya.

## Unguided 

### 1. soal unguided 1
Buat program yang dapat menyimpan data mahasiswa (max.10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts + 0.4*uas + 0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    const int jumlahMhs = 10;
    Mahasiswa mhs[jumlahMhs];
    int i = 0;

    cout << "=== Input Data Mahasiswa (maks 10) ===" << endl;
    cout << "Masukkan NIM = 0 untuk berhenti." << endl;

    while (i < jumlahMhs) {
        cout << "\nNIM : ";
        cin >> mhs[i].nim;

        if (mhs[i].nim == 0) {
            break; 
        }

        cin.ignore(); 
        cout << "Nama : ";
        getline(cin, mhs[i].nama);

        cout << "Nilai UTS : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;
        cout << "---------------------" << endl;

        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);

        i++;
    }

    cout << "\nDaftar Nilai Mahasiswa" << endl;
    cout << "==============================" << endl;

    for (int j = 0; j < i; j++) {
        cout << j + 1 << ". NIM: " << mhs[j].nim
            << ", Nama: " << mhs[j].nama
            << ", Nilai Akhir: " << mhs[j].nilaiAkhir << endl;
    }

    return 0;
}

```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-3/Laprak-modul-3/assets/output-1.png)


Kode di atas adalah kode yang berfungsi sebagai pemrosesan data mahasiswa yang sederhana, menggunakan struct Mahasiswa untuk mengorganisir data (nama, NIM, nilai UTS, UAS, Tugas) dan sebuah fungsi terpisah nilaiAkhir untuk menghitung nilai akhir berdasarkan bobot yang ditentukan, kemudian menyimpan data hingga maksimal 10 mahasiswa ke dalam sebuah array sebelum mencetak daftar ringkasan NIM, Nama, dan Nilai Akhir dari semua data yang berhasil diinputkan.

### 2. soal unguided 2
Buatlah ADT pelajaran sebagai berikut didalam file "pelajaran.h"
    Type pelajaran <
        namaMapel : string
        kodeMapel : string
    >
    function create_pelajaran(namapel : string, kodepel : string) -> pelajaran
    procedure tampil_pelajaran( input pel : pelajaran)

buatlah implementasi ADT pada file "pelajaran.cpp" dan cobalah hasil implementasi pada file "main.cpp"

```C++
//KODE <pelajaran.h> Start 
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodePel);

void tampil_pelajaran(pelajaran pel);

#endif
//KODE <pelajaran.h> End 

//KODE <pelajaran.cpp> Start
#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran: " << pel.namaMapel << endl;
    cout << "nilai: " << pel.kodeMapel << endl;
}
//KODE <pelajaran.cpp> End

//KODE <main.cpp> Start
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
//KODE <main.cpp> End

```
### Output Unguided 2:

![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-3/Laprak-modul-3/assets/output-2.png)

Kode di atas adalah kode yang berfungsi sebagai bagaimana ADT memisahkan apa yang dilakukan oleh tipe data (didefinisikan di .h) dari bagaimana implementasinya (dikerjakan di .cpp), untuk mengahasilkan output nama matakuliah beserta kodenya.

### 3. soal unguided 3
Buatlah program dengan ketentuan :
    - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
    - fungsi/procedure yang menampilkan isi sebuah array integer 2D
    - fungsi/procedure yang akan menukar isi dari 2 array integer 2D pada posisi tertentu
    - fungsi/procedure yang akan menukar isi dari variable yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void menukarIsi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void ubahDenganPointer(int *ptr1, int *ptr2, int nilaiBaru1, int nilaiBaru2) {
    *ptr1 = nilaiBaru1;  
    *ptr2 = nilaiBaru2; 
}

int main() {
    int arrA[3][3] = {
        {12, 2, 8},
        {8, 11, 6},
        {7, 8, 5}
    };

    int arrB[3][3] = {
        {9, 2, 23},
        {1, 1, 1},
        {8, 4, 3}
    };

    cout << "=== Array A ===" << endl;
    tampilArray(arrA);
    cout << "=== Array B ===" << endl;
    tampilArray(arrB);

    int baris = 1, kolom = 1;
    menukarIsi(arrA, arrB, baris, kolom);

    cout << "\n=== Setelah Penukaran ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(arrA);
    cout << "Array B:" << endl;
    tampilArray(arrB);

    cout << "\n=== Ubah Dua Nilai Array A dengan Dua Pointer ===" << endl;
    int barisPtr1 = 0, kolomPtr1 = 1;
    int barisPtr2 = 2, kolomPtr2 = 0;

    int *ptr1 = &arrA[barisPtr1][kolomPtr1];
    int *ptr2 = &arrA[barisPtr2][kolomPtr2];

    cout << "Sebelum diubah: arrA[" << barisPtr1 << "][" << kolomPtr1 << "] = " << *ptr1 
         << ", arrA[" << barisPtr2 << "][" << kolomPtr2 << "] = " << *ptr2 << endl;

    ubahDenganPointer(ptr1, ptr2, 15, 12);

    cout << "Setelah diubah melalui dua pointer:" << endl;
    cout << "arrA[" << barisPtr1 << "][" << kolomPtr1 << "] = " << arrA[barisPtr1][kolomPtr1] << endl;
    cout << "arrA[" << barisPtr2 << "][" << kolomPtr2 << "] = " << arrA[barisPtr2][kolomPtr2] << endl;

    cout << "\n=== Array A Sekarang ===" << endl;
    tampilArray(arrA);

    return 0;
}

```
### Output Unguided 3 :

![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-3/Laprak-modul-3/assets/output-3.png)

Program di atas, program menunjukan memiliki 2 buah array 3x3 menggunakan array 2 dimensi dan 2 buah pointer, dimana terdapat 2 buah fungsi untuk menampilkan array. Lalu menukar nilai pada posisi array1 dan arrray2, Lalu menukar nilai array dengan nilai pada 2 buah pointer.

## Kesimpulan
Pada praktikum Modul 3 ini, mahasiswa mempelajari materi tentang Abstract Data Type (ADT)

konsep fundamental Abstract Data Type (ADT) telah  dipahami dan diimplementasikan, terutama melalui pemisahan antara spesifikasi (.h) dan realisasi (.cpp), seperti yang ditunjukkan pada implementasi ADT Pelajaran[2]. Melalui praktikum ini, praktikan dapat mendefinisikan tipe data baru (struct) dan mengelompokkannya dengan operasi dasar (primitif) yang relevan, menjadikan kode program lebih modular dan reusable. Selain ADT, praktikum juga mencakup penerapan struktur data kolektif, yaitu Array 1D untuk menyimpan sekumpulan objek ADT Mahasiswa dan Array 2D untuk memanipulasi data matriks, serta penggunaan Pointer untuk operasi penukaran nilai variabel secara langsung melalui alamat memorinya, menegaskan pemahaman tentang pengelolaan data dan memori dalam konteks pemrograman prosedural C++[2].

## Referensi
[1] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>
[2] Fitriyani, D., dkk. (2022). Algoritma dan Pemrograman dalam Bahasa C++. UMSIDA Press. Diakses dari https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4/759

