# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Seiring dengan kemajuan teknologi dan informasi saat ini sudah semakin banyak tersedia ragam media pembelajaran. Berbagai ragam media pembelajaran tersebut bisa diterapkan pada matakuliah di program studi informatika baik pada matakuliah teori maupun praktikum [1]. Pada praktikum struktur data kali ini bahas yang digunakan adalah bahasa c++. C++ bukan sekadar bahasa pemrograman, tapi jendela untuk melihat bagaimana data benar-benar bekerja di dalam memori. Praktikum ini akan membekali Anda dengan kunci dasar agar bisa membuka pintu ke dunia struktur data yang lebih kompleks. Bahasa C++ merupakan bahasa pemrograman tingkat menengah yang dikembangkan oleh Bjarne Stroustrup pada awal 1980-an sebagai pengembangan dari bahasa C dengan menambahkan paradigma object-oriented programming (OOP). C++ banyak digunakan dalam bidang system programming, game development, hingga pengembangan perangkat lunak performa tinggi.

Beberapa konsep dasar C++ yang relevan dalam praktikum struktur data adalah:
    1. Tipe Data dan Variabel -> digunakan untuk menyimpan nilai.
    2. Input Output -> untuk menerima masukan user dan mengeluarkan hasil
    3. Kontrol Alur -> meliputi conditional statement (if) dan perulangan (for, while, do-while).
    4. Array -> struktur data statis untuk penyimpanan sekuensial.
    5. Operator Matematika -> operasi perhitungan, oeprasi perbandingan, logika matematika, dll [2]


### A. Materi Praktikum <br/>
...
### 1. Input & Output
### 2. Operasi Matematika 
### 3. Prulangan For
### 4. Prulangan While- do while
### 5. Percabangan If-else if- else
### 6. Struct

### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
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

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-1/Laprak_Modul-1/assets/Output-soal2.png)


Program di atas, program berfungsi untuk meminta 2 inputan bertipe data float kepada user, yang dimana 2 inputan tadi digunakan untuk melakukan operasi matematika penjumlahan, pengurangan, perkalian, dan pembagian oleh program. 

### 2. soal unguided 2
Buatlah program  yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100
    contoh : 79 : tujuh puluh sembilan

```C++
#include <iostream>
using namespace std;

int main() {
    string satuan[] = {
        "", " satu", " dua", " tiga", " empat", " lima", " enam", " tujuh", " delapan", " sembilan"
    };
    string belasan[] = {
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas",
        "tujuh belas", "delapan belas", "sembilan belas"
    };
    string puluhan[] = {
        "", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", 
        "delapan puluh", "sembilan puluh"
    };

    int bil;

    cout << "Masukan angka : ";
    cin >> bil;

    string hasil = "";

    if (bil == 0) {
        hasil = "nol";
    };
    if (bil == 100){ 
        hasil = "seratus";
    }


    if (bil < 10) {
        hasil = satuan[bil];
    }
    else if ( bil < 20 ) {
        hasil = belasan[bil-10];
    }
    else {
        hasil = puluhan[bil/10];
        if (bil % 10 != 0) 
        {
            hasil += "" + satuan[bil%10];
        }    
    }

    cout << bil << " : " << hasil << endl;
    return 0;
}
```
### Output Unguided 2 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-1/Laprak_Modul-1/assets/Output-soal2.png)

Program di atas, program berfungsi untuk meminta inputan kepada user. dimana program memiliki array yang akan digunakan untuk menyimpan data string sesaui dengan index yg sudah dicatta. Program akan melihat kondisi dai inputan user. Lalu program akan mengeluarkan output berupa string.

### 3. soal unguided 3
Buatlah program  yang dapat memberikan input dan output sbb.
    input : 3
    output :
        3 2 1 * 1 2 3
          2 1 * 1 2
            1 * 1
              *

```C++
#include <iostream>
using namespace std;

int main() {
    int n;    cout << "Input : ";
    cin >> n;

    cout << "Output : " << endl;

    for (int i = n; i >= 1 ; i--) {
        for (int spasi = 0; spasi < (n - i); spasi++) {
            cout << "  "; 
        }
        for (int sisiKiri = i; sisiKiri >= 1; sisiKiri--){            
            cout << sisiKiri << " ";
        }

        cout << " * ";

        for (int sisiKanan = 1; sisiKanan <= i; sisiKanan++){
            cout << sisiKanan << " ";
        }
        
        cout << endl;  
    }
    
    for (int lastSpasi = 0; lastSpasi < n; lastSpasi++) {
        cout << "  ";
    }
    cout << " * " << endl;
    return 0;
    
}
```
### Output Unguided 3 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-1/Laprak_Modul-1/assets/Output-soal3.png)

Program di atas, program berfungsi untuk meminta inputan user untuk menentukan baris segitiga piramida terbalik, lalu program akan melakukan sebuah perulangan untuk baris dan juga index angka perulangannya hingga membentuk output segitiga piramid terblik yang di akhiri dengan *

## Kesimpulan
Pada praktikum Modul 1 ini, mahasiswa diperkenalkan dengan VS code dan konsep dasar bahasa C++. Melalui serangkaian percobaan baik guided maupun unguided, mahasiswa mampu:
    1. Memahami dasar input-output menggunakan cin dan cout.
    2. Menerapkan operator matematika dalam operasi penjumlahan, pengurangan, perkalian, pembagian, dan modulus.
    3. Menggunakan struktur kontrol seperti perulangan (for, while, do-while) dan percabangan (if-else).
    4. Menerapkan struct sebagai bentuk dasar pemrograman terstruktur untuk menyimpan data majemuk.
    5. Menyelesaikan soal unguided yang melatih pemahaman logika pemrograman, manipulasi array, serta pola perulangan.

Dengan dasar ini, mahasiswa diharapkan mampu membangun fondasi yang kuat untuk memahami implementasi struktur data pada praktikum berikutnya, karena C++ memberikan kontrol penuh terhadap memori sekaligus fleksibilitas dalam pemrograman prosedural maupun berorientasi objek.

## Referensi
[1] Saputri, N. A. O., Hannah, M. P., & Suroyo, H. (2017, October). EFEKTIFITAS PENGGUNAAN WEB-BASED-LEARNING PADA MATAKULIAH PRAKTIKUM STRUKTUR DATA DENGAN BAHASA C++. In Prosiding Seminar Nasional Darmajaya (Vol. 1, No. 1, pp. 19-27). 
<br>
[2] Seidametova, Z.S. (2021). Some ways of increasing the efficiency of teaching data structures. CEUR Workshop Proceedings.
<br>

