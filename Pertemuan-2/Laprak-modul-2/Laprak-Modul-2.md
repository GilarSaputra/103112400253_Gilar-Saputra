# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
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
#### 2. Soal Unguided 2 (a, b)
#### 3. Soal Unguided 3


## Guided 

### 1. Array 1 dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << " isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
    
}
```
Kode di atas adalah kode yang berfungsi untuk menampilkan angka atau bilangan bertipe data number (integer) sesuai inputan yang user inginkan pada index ke 0-4 dengan array 1 dimensi

### 2. Array 2 dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) { 
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {   
            for (int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil Perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk melakukan sebuah operasi matematika berupa penjumlahan dan perkalian dari matriks 2x2 menggunakan array 2 dimensi.

### 3. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Adress of a : " << &a << endl;
    cout << "Value stored in ptr (adress of a) : " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk melakukan pertukaran sebuah nilai menggunakan pointer (*).

### 4. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;


    cout << "Nilai a : " << a << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Nilai ref (alias a) : " << ref << endl;
    cout << "alamat ref (&ref) : " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;


    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk melakukan pertukaran sebuah nilai menggunakan alias / reference (&).


### 5. Fungsi

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if(arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "total penjumlaan : " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for ( int i = 0; i < ukuran; i++) {
        cout << "masukan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk menentukan nilai tertinggi didalam array, dan melakukan penjumlahan serta perkalian aritmatika yang mengimplementasikan sebuah fungsi, array, looping.

## Unguided 

### 1. soal unguided 1
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3;j++) {
            cout << arr[i][j] << " ";
        }
            cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {2, 6, 8},
        {3, 5 ,1},
        {4, 8, 2}
    };
    int arrB[3][3] = {
        {1, 3, 3},
        {3, 2 ,0},
        {3, 4, 1}
    };  
    
    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    // Penjumlahan
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    // Pengurangan
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil Pengurungan : " << endl;
    tampilkanHasil(arrD);
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {   
            for (int k = 0; k < 3; k++) {
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil Perkalian : " << endl;
    tampilkanHasil(arrE);

    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-2/Laprak-modul-2/assets/output-1.png)


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

