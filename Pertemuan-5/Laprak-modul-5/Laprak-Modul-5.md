# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Singly Linked List merupakan salah satu struktur data dinamis yang terdiri dari sekumpulan elemen yang disebut node, di mana setiap node memiliki dua bagian utama, yaitu data dan pointer yang menunjuk ke node berikutnya. Berbeda dengan array yang memiliki ukuran tetap, singly linked list memungkinkan penambahan serta penghapusan elemen secara fleksibel tanpa perlu menggeser data lain. Node pertama disebut head, sedangkan node terakhir menunjuk ke nullptr sebagai penanda akhir list [3]. Dalam implementasinya di bahasa C++, singly linked list menggunakan struct untuk mendefinisikan node yang berisi data bertipe dasar seperti int dan pointer bertipe address. Manipulasi list dilakukan melalui fungsi-fungsi seperti insertFirst(), insertLast(), insertAfter(), delAfter(), dan printList(), sesuai dengan prinsip Abstract Data Type (ADT), di mana operasi terhadap data dilakukan melalui fungsi tanpa mengakses struktur internal secara langsung. Program ini juga menambahkan operasi tambahan seperti update untuk memperbarui nilai node, search untuk pencarian berdasarkan data, alamat, dan rentang nilai, serta operasi aritmetika seperti penjumlahan, pengurangan, dan perkalian antar node [1]. Kelebihan singly linked list terletak pada efisiensi dalam menambah dan menghapus data karena tidak memerlukan penggeseran elemen, sementara kelemahannya adalah akses data yang bersifat sekuensial, sehingga pencarian elemen memerlukan penelusuran dari node pertama hingga node yang diinginkan [3].

### A. Materi Praktikum <br/>
...
#### 1. Single Link List Lanjutan (Searching, update)


### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Singly Linked list 1
listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah;

typedef struct node *address;

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas merupakan implementasi struktur data linked list dalam bahasa C++ untuk mengelola data buah secara dinamis. Struktur utama yang digunakan terdiri dari tiga bagian, yaitu buah, node, dan linkedlist. Struktur buah berfungsi untuk menyimpan data setiap buah seperti nama, jumlah, dan harga. Struktur node menyimpan satu data buah (isidata) serta pointer next yang menunjuk ke node berikutnya. Sedangkan struktur linkedlist menyimpan alamat node pertama (first) sebagai penanda awal list.

Pada file listBuah.cpp, berbagai fungsi didefinisikan untuk memanipulasi data dalam linked list. Fungsi dasar seperti createList() digunakan untuk menginisialisasi list agar kosong, sedangkan isEmpty() memeriksa apakah list sudah berisi data atau belum. Fungsi alokasi() membuat node baru dengan data buah yang diberikan, dan dealokasi() menghapus node dari memori. Untuk menambah data ke dalam list, digunakan fungsi insertFirst(), insertAfter(), dan insertLast() yang masing-masing menambahkan node di awal, setelah node tertentu, dan di akhir list.

Selain itu, terdapat fungsi penghapusan seperti delFirst(), delLast(), dan delAfter() yang menghapus node pertama, terakhir, atau setelah node tertentu. Fungsi deleteList() akan menghapus seluruh isi list hingga kosong. Program juga menyediakan fitur untuk memperbarui data, yaitu updateFirst(), updateLast(), dan updateAfter() untuk mengubah isi node pertama, terakhir, atau setelah node tertentu. Untuk pencarian data, digunakan fungsi FindNodeByData() untuk mencari buah berdasarkan nama, FindNodeByAddress() untuk mencari berdasarkan alamat node, dan FindNodeByRange() untuk mencari buah dengan harga dalam rentang tertentu.

Pada file main.cpp, fungsi-fungsi tersebut diuji. Program dimulai dengan membuat list kosong, lalu menambahkan beberapa buah seperti Jeruk, Apel, Pir, Semangka, dan Durian menggunakan kombinasi fungsi insert. Setelah itu, data ditampilkan, diupdate, serta dicari berdasarkan kriteria tertentu. Program juga mendemonstrasikan proses penghapusan node dan pengosongan seluruh list. Secara keseluruhan, program ini menunjukkan bagaimana linked list dapat digunakan untuk menambah, menghapus, mengubah, menelusuri, dan mencari data secara fleksibel menggunakan pointer dan memori dinamis di C++.

## Unguided 
Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h” :
```
Type dataAngka : int
Type address : pointer to node
Type node <
Angka : dataAngka
Next : address
>
Type linkedList : < First : address >
Procedure CreateList( input / output L : List )
Function alokasi ( x : infotype ) → address
Procedure dealokasi ( input / output node : address )
Procedure printList ( input L : List )
Procedure insertFirst ( input / output L : List, input nodeBaru : address )
Procedure insertLast ( input / output L : List, input nodeBaru : address )
Procedure insertAfter ( input / output L : List, input nodeBaru : address, input nodePrev : address )
Function nbList (input L : List ) integer
Procedure delAfter ( input / output L : List, input nodeHapus : address, input nodePrev : address )
```
kemudian buatlah implementasi function & procedure tersebut pada file “listAngka.cpp”
kemudian lakukan hal berikut pada file “main.cpp”
```
Buat nodeA, nodeB, nodeC, nodeD, nodeE, nodeF
nodeA = alokasi(8);
nodeB = alokasi(13);
nodeC = alokasi(18);
nodeD = alokasi(25);
nodeE = alokasi(33);
nodeF = alokasi(40);
insertFirst nodeB
insertLast nodeA
insertAfter nodeD setelah nodeB
insertFirst nodeC
insertLast nodeE
insertFirst nodeF
delAfter nodeB setelah nodeC
Tampilkan seluruh isi list
```
Output yang diharapkan :
```
40 - 18 - 25 - 8 - 33 -
```

### Jawaban
Kode ini adalah dasar ADT dimana nantinya akan ada lanjutan kodenya pada unguided point 1-3 (kode ini saling berhubungan) <br/>
ListAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;

struct node;
typedef node* address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

#endif
```

ListAngka.cpp
```C++
#include "ListAngka.h"

void CreateList(linkedList &L){
    L.First = nullptr;
}

address alokasi(dataAngka x){
    address P = new node;
    if (P != nullptr){
        P->Angka = x;
        P->Next = nullptr;
    }    
    return P;
}

void dealokasi(address node){
    delete node;
}

void printList(linkedList L){
    address P = L.First;
    while (P!= nullptr) {
        cout << P->Angka << " - ";
        P = P->Next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address nodeBaru){
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(linkedList &L, address nodeBaru){
    if(L.First == nullptr) {
        L.First = nodeBaru;
    } else {
        address P = L.First;
        while (P->Next != nullptr){
            P = P->Next;
        }
        P->Next = nodeBaru;
    }
}

void insertAfter(linkedList &L, address nodeBaru, address nodePrev){
    if (nodePrev != nullptr) {
        nodeBaru->Next = nodePrev->Next;
        nodePrev->Next = nodeBaru;
    }
}

int nbList(linkedList L){
    int count = 0;
    address P = L.First;
    while (P != nullptr) {
        count++;
        P = P->Next;
    }
    return count;
}

void delAfter(linkedList &L, address nodeHapus, address nodePrev){
    if (nodePrev != nullptr && nodePrev->Next != nullptr) {
        nodeHapus = nodePrev->Next;
        nodePrev->Next = nodeHapus->Next;
        dealokasi(nodeHapus);
    }
}
```

main.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    CreateList(L);

    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);     
    insertLast(L, nodeA);       
    insertAfter(L, nodeD, nodeB); 
    insertFirst(L, nodeC);
    insertLast (L, nodeE);
    insertFirst (L, nodeF);
    delAfter (L, nodeB, nodeC);

    printList(L);  
    // Jawaban Point 1
    // Jawaban Point 2
    // Jawaban Point 3
    
    return 0
}
```
### Output :
![Screenshot Output](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-5/Laprak-modul-5/assets/output.png)

### 1. soal unguided 1
Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian sebagai berikut :
```
Procedure updateFirst ( input / output L : List )
Procedure updateLast ( input / output L : List )
Procedure updateAfter ( input / output L : List, input nodePrev : address )
```
Kemudian pada “main.cpp” lakukanlah :<br/>
    ➢ Update data 40 menjadi 50 <br/>
    ➢ Update data 8 menjadi 29 <br/>
    ➢ Update data 33 menjadi 45 <br/>
    ➢ Update data 18 menjadi 20 <br/>
    ➢ Tampilkan seluruh list setelah diupdate <br/>
### Jawaban
Tambahkan kode berikut pada : <br/>
ListAngka.h
```C++
// Soal Nomor 1
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodeprev);
```

ListAngka.cpp
```C++
// Soal Nomor 1
void updateFirst(linkedList &L) {
    if (L.First != nullptr) {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> L.First->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.First == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }

    address P = L.First;
    while (P->Next != nullptr) {
        P = P->Next;
    }

    cout << "Masukkan update data node terakhir : " << endl;
    cout << "Masukkan angka : ";
    cin >> P->Angka;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateAfter(linkedList &L, address nodePrev) {
    if (nodePrev != nullptr && nodePrev->Next != nullptr) {
        cout << "Masukkan update data node setelah " << nodePrev->Angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodePrev->Next->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
    } else {
        cout << "Node tidak valid atau tidak ada node setelahnya!" << endl;
    }
}
```

main.h
```C++
    // Soal Nomor 1
    cout << "List sebelum update:" << endl;
    printList(L);              

    updateFirst(L);          
    updateAfter(L, nodeD);   
    updateLast(L);       
    updateAfter(L, nodeF);  

    cout << endl << "List setelah update:" << endl;
    printList(L);     
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-5/Laprak-modul-5/assets/output-1.png)

 Program di atas adalah lanjutan dari sebuah program awal pada unguided, dimana program ini melakukan penambahan : <br/>
 Program menambahkan fitur untuk mengubah (update) data pada node dalam struktur linked list. Tiga fungsi baru ditambahkan, yaitu `updateFirst()`, `updateLast()`, dan `updateAfter()`. Fungsi `updateFirst()` digunakan untuk memperbarui nilai data pada node pertama dalam list, sedangkan `updateLast()` memperbarui nilai pada node terakhir dengan cara menelusuri list hingga ke ujung. Sementara itu, `updateAfter()` berfungsi untuk memperbarui data pada node yang berada setelah node tertentu yang ditentukan melalui parameter `nodePrev`. Pada bagian `main.cpp`, program menampilkan isi list sebelum dan sesudah proses update agar perubahan terlihat jelas. Dengan penambahan fitur ini, program tidak hanya dapat menambah atau menghapus data, tetapi juga mampu memodifikasi nilai node secara fleksibel di posisi manapun dalam linked list.

### 2. soal unguided 2
Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan rincian sebagai berikut :
```
Procedure SearchByData( input L : List, input data : integer )
Procedure SearchByAddress( input L : List, input node : address )
Procedure SearchByRange( input L : List, input nilaiMin : integer )
```
Kemudian pada “main.cpp” lakukanlah : <br/>
    ➢ Mencari data nilai 20 <br/>
    ➢ Mencari data nilai 55 <br/>
    ➢ Mencari data alamat nodeB <br/>
    ➢ Mencari data alamat nodeA <br/>
    ➢ Mencari data dengan nilai minimal 40 <br/>
### Jawaban
Tambahkan kode berikut pada : <br/>
ListAngka.h
```C++
// soal Nomor 2
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, int nilaiMin);
```

ListAngka.cpp
```C++
// Soal Nomor 2
void SearchByData(linkedList L, int data) {
    address P = L.First;
    int posisi = 1;
    bool found = false;

    while (P != nullptr) {
        if (P->Angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        P = P->Next;
        posisi++;
    }

    if (!found) {
        cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
    }
    cout << endl;
}

void SearchByAddress(linkedList L, address node) {
    address P = L.First;
    int posisi = 1;
    bool found = false;

    while (P != nullptr) {
        if (P == node) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << P << endl;
            found = true;
            break;
        }
        P = P->Next;
        posisi++;
    }

    if (!found) {
        cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
    }
    cout << endl;
}

void SearchByRange(linkedList L, int nilaiMin) {
    address P = L.First;
    int posisi = 1;
    bool found = false;

    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    cout << "-----------------------------------------" << endl;

    while (P != nullptr) {
        if (P->Angka >= nilaiMin) {
            cout << "Data ditemukan pada posisi ke-" << posisi
                << ", nilai : " << P->Angka << endl;
            found = true;
        }
        P = P->Next;
        posisi++;
    }

    if (!found) {
        cout << "Tidak ada data dengan nilai di atas " << nilaiMin << endl;
    }
    cout << endl;
}
```

main.cpp
```C++
    // Soal Nomor 2
    SearchByData(L, 20);   
    SearchByData(L, 55);  
    SearchByAddress(L, nodeB); 
    SearchByAddress(L, nodeA); 
    SearchByRange(L, 40); 
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-5/Laprak-modul-5/assets/output-2.png)

 Program di atas adalah lanjutan dari sebuah program awal pada unguided, dimana program ini melakukan penambahan : <br/>
Program menambahkan fitur pencarian data dalam linked list menggunakan tiga metode berbeda. Fungsi `SearchByData()` digunakan untuk mencari node berdasarkan nilai data tertentu, dengan menampilkan posisi node jika ditemukan. Fungsi `SearchByAddress()` melakukan pencarian berdasarkan alamat node (pointer), berguna untuk memastikan posisi node tertentu di memori. Sedangkan `SearchByRange()` mencari dan menampilkan semua node yang memiliki nilai lebih besar atau sama dengan batas minimum (nilaiMin) yang diberikan. Pada bagian main.cpp, ketiga fungsi ini diuji dengan berbagai parameter untuk memastikan setiap metode pencarian berjalan dengan baik. Dengan demikian, fitur ini membuat program mampu melakukan pencarian data secara lebih fleksibel dan informatif, baik berdasarkan nilai, alamat, maupun rentang nilai dalam linked list.

### 3. soal unguided 3
Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.
### Jawaban
Tambahkan kode berikut pada : <br/>
ListAngka.h
```C++
// Soal Nomor 3
void penjumlahanList(linkedList L);
void penguranganList(linkedList L);
void perkalianList(linkedList L);
```

ListAngka.cpp
```C++
// SoalNomor 3
void penjumlahanList(linkedList L) {
    address P = L.First;
    int total = 0;

    while (P != nullptr) {
        total += P->Angka;
        P = P->Next;
    }

    cout << "Total penjumlahan : " << total << endl;
}

void penguranganList(linkedList L) {
    if (L.First == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }

    address P = L.First->Next;
    int total = L.First->Angka; 

    while (P != nullptr) {
        total -= P->Angka;
        P = P->Next;
    }

    cout << "Total pengurangan : " << total << endl;
}

void perkalianList(linkedList L) {
    if (L.First == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }

    address P = L.First;
    long long total = 1;

    while (P != nullptr) {
        total *= P->Angka;
        P = P->Next;
    }

    cout << "Total perkalian : " << total << endl;
}
```

main.cpp
```C++
    // Soal Nomor 3
    cout << endl;
    cout << "===============================" << endl;
    cout << "   Operasi Aritmetika List" << endl;
    cout << "===============================" << endl;

    penjumlahanList(L);
    penguranganList(L);
    perkalianList(L);
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-5/Laprak-modul-5/assets/output-3.png)

 Program di atas adalah lanjutan dari sebuah program awal pada unguided, dimana program ini melakukan penambahan : <br/>
Pada soal nomor 3, program menambahkan fitur untuk melakukan operasi aritmetika pada seluruh elemen linked list, yaitu penjumlahan, pengurangan, dan perkalian. Fungsi `penjumlahanList()` menghitung total dari semua nilai node dalam list dengan cara menjumlahkan tiap elemen satu per satu. Fungsi `penguranganList()` melakukan operasi pengurangan secara berurutan, dimulai dari nilai node pertama lalu dikurangi dengan nilai node-node berikutnya. Sedangkan `perkalianList()` menghitung hasil kali dari semua elemen dalam list menggunakan variabel bertipe long long agar mampu menampung hasil besar. Ketiga fungsi ini kemudian dipanggil di bagian main.cpp untuk menampilkan hasil operasi aritmetika tersebut. Dengan penambahan fitur ini, program menjadi lebih fungsional karena mampu melakukan perhitungan matematis langsung pada data dalam linked list.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa implementasi ADT list melalui struktur singly linked list memberikan kemudahan manipulasi data secara dinamis—termasuk penambahan, penghapusan, pencarian, pembaruan, dan operasi aritmetika terhadap elemen-elemen list[3]. Fleksibilitas ini sangat berguna dalam situasi di mana ukuran data berubah secara dinamis atau diperlukan operasi penyisipan/hapus yang sering. Namun demikian, terdapat batasan ketika akses elemen tidak seefisien array karena harus menelusuri dari head hingga node target. Oleh karena itu, pemilihan struktur data harus disesuaikan dengan kebutuhan aplikasi: jika penyisipan/hapus sering dan ukuran tidak tetap maka SLL sangat cocok; jika akses cepat ke indeks spesifik diperlukan maka struktur seperti array atau list BERIMPLENTASI-LAIN mungkin lebih tepat. Praktikum ini juga menegaskan pentingnya memahami konsep ADT, pointer, alokasi dinamis, dan manajemen memory dalam C++ sebagai bagian dari penguasaan struktur data[3].

## Referensi
[1] Wijoyo, A., Prasetiyo, A. R., Salsabila, A. A., Nife, K., Murni, & Nadapdap, P. B. (2024). Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1244-1246. Diakses dari https://jurnalmahasiswa.com/index.php/jriin/article/view/1060 <br/>
[2]Memahami Konsep dan Jenis-Jenis Linked List dalam Struktur Data.“ (2024). Terapan-TI Vokasi UNESA. Diakses dari https://terapan-ti.vokasi.unesa.ac.id/post/memahami-konsep-dan-jenis-jenis-linked-list-dalam-struktur-data


