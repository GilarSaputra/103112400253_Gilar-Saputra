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

### 1. Input & Output

```C++
#include <iostream>

using namespace std;

int main() {
    int angka;
    cout << "Masukan Angka : ";
    cin >> angka;

    cout << "Angka yang anda masukan adala : " << angka << endl;
    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk menampilkan angka atau bilangan bertipe data number (integer) sesuai inputan yang user inginkan.

### 2. Operasi Matematika 

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    // Penjumlahan
    cout << "Penjumlahan : " << angka1+ angka2 << endl;
    // Pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    // Perkalian 
    cout << "Perkalian : "<< angka1 * angka2 << endl;
    // Pembagian 
    cout << "Pembagia :" << angka1 / angka2 << endl;
    // mOdulus
    cout << "Modulus : " << angka1 % angka2 << endl;
    return 0;
}

```
Kode di atas adalah kode yang berfungsi untuk melakukan sebuah operasi matematika berupa penjumlahan, pengurangan, perkalian, pembagian, dan modulo sesuai dengan 2 inputan dari user.

### 3. Prulangan For

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    for (int i = 0; i <= angka1; i++) // increment
    {
        cout << i << " - ";
    
    }

    cout << endl;
    
    // for (int i = angka1; i >= 0; i--) // decrement
    // {
    //     cout << i << " - ";
    // }

    for (int i = 20; i >= angka2; i--) //decrement
    {
        cout << i << " - ";
    }

    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk melakukan sebuah perulangan dimana program akan menerima 2 inputan user. Dimana inputan pertama, program akan melakukan deret bilangan dari angka  0 sampai angka inputan user. Lalu inputan kedua, program akan melakukan deret bilangan dari angka 20 sampai angka inputan user.

### 4. Prulangan While- do while

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "Masukan angka 1 : ";
    cin >> angka1;

    int i = 0;
    int j = 11;

    while (i < angka1){
        cout << i << " - ";
        i++;
    };

    cout << endl;

    do{
        cout << j << " - ";
        j++;
    } while (j < angka1);
    
    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk melakukan sebuah perulangan dimana program akan menerima 1 inputan user. Dimana inputan tersebut akan menghasilkan sebuah batas perulangan dimana perulangan i dilakukan dari 0 sampai inputan user. Lalu perulangan j dilakuakn dari 11 sampai inputan user.

### 5. Percabangan If-else if- else

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << angka1 << " Lebih besar dari " << angka2 << endl;
    } else if (angka1 == angka2){
        cout << angka1 << " Sama dengan " << angka2 << endl;
    } else if ( angka1 < angka2 ) {
        cout << angka1 << " Lebih kecil dari " << angka2 << endl;
    }
    
    
    if (angka1 != angka2){
        cout << angka1 << " Tidak Sama dengan " << angka2 << endl;
    }

    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk mebandingkan dua buah inputan user berupa angka apakah lebih besar, lebih kecil atau sama dengan, dan tidak sama dengan. Program akan melihat kondisi yang akan di gunakan.

### 6. Struct

```C++
#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct rapot{
        string nama;
        int nilai;
    };

    rapot siswa[jumlah];
    for (int i = 0; i < jumlah; i++){
        cout << "Masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int i = 0;
    while (i < jumlah) {
        cout << "Nama siswa : " << siswa[i].nama << " nilai : " << siswa[i].nilai << endl;
        i++;
    };
    
    return 0;
}
```
Kode di atas adalah kode yang berfungsi untuk mendapatkan inputan user sebanyak len array = jumlah yaitu 5, program akan melakukan perulangan input sebanyak 5 kali, dimana user akan memasukan nama dan nilai. Setelah selesai program akan menambilkan output dari inputan nama dan nilai user sebanyak len array(5).

## Unguided 

### 1. soal unguided 1
Buatlah program  yang menerima input-an dua buah bilangan bertipe data float, kemudian  mmeberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua buah bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float b1, b2;
    cout << "Masukan bilangan 1 : ";
    cin >> b1;
    cout << "Masukan bilangan 2 : ";
    cin >> b2;

    cout << "Hasil Penjumlahan " << b1 << " + " << b2 << " = " << b1 + b2 << endl;
    cout << "Hasil Pengurangan " << b1 << " - " << b2 << " = " << b1 - b2 << endl;
    cout << "Hasil Perkalian " << b1 << " * " << b2 << " = " << b1 * b2 << endl;
    cout << "Hasil Pembagain " << b1 << " / " << b2 << " = " << b1 / b2 << endl;
    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-1/Laprak_Modul-1/assets/Output-soal1.png)


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

