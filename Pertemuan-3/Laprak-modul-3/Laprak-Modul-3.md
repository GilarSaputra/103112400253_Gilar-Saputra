# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Dalam bahasa pemrograman C++, pemahaman tentang array, pointer, reference, dan fungsi merupakan hal fundamental yang harus dikuasai dalam praktik [1]. Array berfungsi untuk menyimpan sejumlah data yang memiliki tipe serupa secara urut di dalam memori, sehingga mempermudah pengelolaan data dalam jumlah besar. Pointer berfungsi sebagai variabel yang memiliki alamat memori, yang memungkinkan akses dan manipulasi data secara langsung serta mempermudah pengelolaan array dan parameter di dalam fungsi. Reference hadir sebagai nama lain untuk variabel lain, yang mempermudah proses pass by reference tanpa perlu menggunakan dereferensi, menjadikannya lebih mudah dibandingkan pointer. Di sisi lain, fungsi berfungsi sebagai blok kode yang dapat dipanggil kembali, membantu membagi program menjadi bagian-bagian modular yang lebih teratur, serta mendukung parameter baik dengan pass by value maupun pass by reference. Dengan memahami hubungan antar konsep ini, mahasiswa dapat menciptakan program yang lebih efisien, terorganisir, dan mudah untuk dipelihara[2].


### A. Materi Praktikum <br/>
...
### 1. Array 1 dimensi
### 2. Array 2 dimensi 
### 3. Pointer
### 4. Reference
### 5. Fungsi

### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1.

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
Kode di atas adalah kode yang berfungsi untuk 

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
Kode di atas adalah kode yang berfungsi 

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


Kode di atas adalah kode yang berfungsi untuk melakukan sebuah operasi matematika berupa penjumlahan, pengurangan dan perkalian dari matriks 3x3 menggunakan array 2 dimensi.

### 2. soal unguided 2
Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

### a. soal unguided 2 menggunakan pointer
```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 20, b = 30, c = 50;

    cout << "Sebelum swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    tukar(&a, &b, &c);

    cout << "Setelah sapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}

```
### Output Unguided 2.a :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-2/Laprak-modul-2/assets/output-2_1.png)

### b. soal unguided 2 menggunakan reference
```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 20, b = 30, c = 50;

    cout << "Sebelum swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    tukar(&a, &b, &c);

    cout << "Setelah sapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}

```
### Output Unguided 2.b :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-2/Laprak-modul-2/assets/output-2_2.png)

Program di atas, program berfungsi untuk melakukan pertukaran nilai 3 variable dimana variable temp sebagai variable penyimpan nilai sementara menggunakan pointer dan juga reference.

### 3. soal unguided 3
Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMaksimum(int arrA[], int ukuran) {
    int MAX = arrA[0];
    for (int i = 1; i < ukuran; i++) {
        if (arrA[i] > MAX) {
            MAX = arrA[i];
        }
    }
    return MAX;
}

int cariMinimum(int arrA[], int ukuran) {
    int MIN = arrA[0];
    for (int i = 1; i < ukuran; i++) {
        if (arrA[i] < MIN) {
            MIN = arrA[i];
        }
    }
    return MIN;
}

void hitungRataRata(int arr[], int ukuran) {
    int sum = 0;
    for (int i = 0; i < ukuran; i++) {
        sum += arr[i];
    }
    double rata = (double)sum / ukuran;
    cout << "Nilai rata-rata = " << rata << endl;
}

void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int ukuran = 10;
    int arrA[ukuran] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int input;

        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "Pilih menu: ";
        cin >> input;

        switch (input) {
            case 1:
                tampilkanArray(arrA, ukuran);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    return 0;
}

```
### Output Unguided 3 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-2/Laprak-modul-2/assets/output-3.png)

Program di atas, program berfungsi untuk meminta inputan user untuk menentukan menu mana yang akan dipilih sesuai yang di tampilkan di terminal dimana user dapat melihat "Isi array", "nilai minimum", "nilai maksimum", "nilai rata-rata"

## Kesimpulan
Pada praktikum Modul 2 ini, mahasiswa mempelajari materi tentang array (array 1 dimensi dan 2 dimensi), pointer dan reference, serta fungsi dan void. 

Array : struktur data yang menyimpan banyak elemen bertipe sama secara berurutan di memori, diakses dengan indeks.
Pointer : variabel yang menyimpan alamat memori; berguna untuk manipulasi data, array, dan fungsi.
Reference : alias dari variabel lain, memudahkan pass by reference tanpa perlu dereferensi seperti pointer.
Fungsi : blok kode yang dapat dipanggil ulang, mendukung pass by value atau pass by reference, serta bisa bersifat rekursif untuk memecah masalah. [1]

## Referensi
[1] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>
[2] Fitriyani, D., dkk. (2022). Algoritma dan Pemrograman dalam Bahasa C++. UMSIDA Press. Diakses dari https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4/759

