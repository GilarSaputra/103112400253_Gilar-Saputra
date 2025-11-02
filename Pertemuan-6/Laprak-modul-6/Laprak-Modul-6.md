# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Kedua)</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Struktur data DLL adalah varian dari linked list di mana setiap elemen (node) memiliki dua penunjuk (pointer) — satu menunjuk ke node berikutnya (next) dan satu lagi ke node sebelumnya (prev). Dengan demikian, traversal atau penelusuran dapat dilakukan dari depan ke belakang maupun dari belakang ke depan, tanpa harus menelusuri seluruh list dari awal terlebih dahulu. Keunggulan ini membuat DLL sangat cocok digunakan ketika operasi seperti penyisipan (insert) atau penghapusan (delete) di posisi tertentu (awal, tengah, akhir) dibutuhkan dengan efisiensi lebih baik dibandingkan list satu arah. Sebagaimana ditunjukkan dalam penelitian bahwa DLL memungkinkan navigasi dua arah secara langsung sehingga mempercepat proses manipulasi data.[1]

Dalam implementasi ADT (Abstract Data Type), sebuah list ganda biasanya didefinisikan dengan operasi dasar seperti inisialisasi list kosong (createList), alokasi dan dealokasi node (allocate dan deallocate), penambahan node di akhir (insertLast), pencetakan isi list (printInfo), pencarian node (findElm), hingga penghapusan node di berbagai posisi (awal, akhir, setelah node tertentu).[1] Pendekatan ADT ini membantu membuat kode modular, memisahkan logika struktur data dari logika aplikasi, sehingga memudahkan pemeliharaan dan pengembangan lebih lanjut. Sebuah studi Indonesia menegaskan bahwa fleksibilitas linked list dalam penyisipan dan penghapusan membuatnya lebih dinamis dibandingkan array meskipun akses langsung kurang cepat.[2]

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
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

listMakanan.cpp
```C++
#include "listMakanan.h"
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
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Kode di atas merupakan implementasi struktur data Doubly Linked List (DLL) dalam bahasa C++ untuk menyimpan dan memanipulasi data makanan. Program ini menggunakan tiga file: listMakanan.h untuk mendefinisikan struktur data dan deklarasi fungsi, listMakanan.cpp untuk implementasi fungsi-fungsi manipulasi list, dan main.cpp untuk menjalankan program utama.

Struktur makanan menyimpan atribut setiap makanan seperti nama, jenis, harga, dan rating. Setiap node (struct node) berisi data makanan dan dua pointer (next dan prev) yang saling menghubungkan antar-node, sedangkan linkedlist menyimpan pointer ke node pertama dan terakhir dalam list. Fungsi-fungsi utama yang diimplementasikan mencakup pembuatan list (createList), pengecekan list kosong (isEmpty), pembuatan node baru (alokasi), penambahan node di berbagai posisi (insertFirst, insertLast, insertAfter, insertBefore), penampilan isi list (printList), dan pembaruan data pada node tertentu (updateFirst, updateLast, updateAfter, updateBefore).

### 2. Guided 2
listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
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
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

main.cpp
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Kode di atas merupakan implementasi struktur data Doubly Linked List (DLL) dalam bahasa C++ untuk mengelola data makanan secara dinamis. Program ini terdiri dari tiga file: listMakanan.h (deklarasi struktur dan fungsi), listMakanan.cpp (implementasi logika), dan main.cpp (fungsi utama). Setiap node menyimpan data makanan seperti nama, jenis, harga, dan rating, serta dua pointer (next dan prev) yang menghubungkan antar-node. Program mendukung berbagai operasi seperti menambah node di awal, akhir, sebelum, atau sesudah node tertentu; menampilkan isi list; memperbarui data pada node pertama, terakhir, sebelum, atau sesudah node tertentu; mencari data berdasarkan nama, jenis, atau minimal rating; serta menghapus node berdasarkan posisi atau nama.

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
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

// Nomor 1
struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    Kendaraan info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(Kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"

// Nomor 1
void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(Kendaraan x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;
    if (P == NULL) {
        cout << "List kosong" << endl;
    } else {
        cout << "\nDATA LIST 1\n";
        while (P != NULL) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->prev;
        }
    }
}
```

main.h
```C++
#include "Doublylist.h"

// Nomor 1
bool findNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Kendaraan k;
        cout << "\nmasukkan nomor polisi: ";
        cin >> k.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> k.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> k.thnBuat;

        if (findNopol(L, k.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            address P = alokasi(k);
            insertLast(L, P);
        }
    }

    printInfo(L);
    return 0;
}    
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
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

// Nomor 1
struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    Kendaraan info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(Kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Nomor 2
address findElm(List L,Kendaraan x);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"

// Nomor 1
void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(Kendaraan x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;
    if (P == NULL) {
        cout << "List kosong" << endl;
    } else {
        cout << "\nDATA LIST 1\n";
        while (P != NULL) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->prev;
        }
    }
}

// Nomor 2
address findElm(List L, Kendaraan x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
```

main.cpp
```C++
#include "Doublylist.h"

// Nomor 1
bool findNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Kendaraan k;
        cout << "\nmasukkan nomor polisi: ";
        cin >> k.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> k.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> k.thnBuat;

        if (findNopol(L, k.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            address P = alokasi(k);
            insertLast(L, P);
        }
    }

    printInfo(L);

    Kendaraan cari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != NULL) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan!" << endl;
    }

    return 0;
}
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
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

// Nomor 1
struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    Kendaraan info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(Kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Nomor 2
address findElm(List L, Kendaraan x);

// Nomor 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"

// Nomor 1
void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(Kendaraan x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    cout << "\nDATA LIST 1\n";
    address P = L.Last;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Nomor 2
address findElm(List L, Kendaraan x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// Nomor 3
void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = NULL;
        L.Last = NULL;
    } else {
        P = L.First;
        L.First = L.First->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = NULL;
        L.Last = NULL;
    } else {
        P = L.Last;
        L.Last = L.Last->prev;
        L.Last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}
```

main.cpp
```C++
#include "Doublylist.h"

bool findNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Kendaraan k;
        cout << "\nmasukkan nomor polisi: ";
        cin >> k.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> k.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> k.thnBuat;

        if (findNopol(L, k.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            address P = alokasi(k);
            insertLast(L, P);
        }
    }

    printInfo(L);

    // Nomor 2: Cari elemen
    Kendaraan cari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != NULL) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan!" << endl;
    }

    // Nomor 3: Hapus elemen
    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address P = L.First;
    while (P != NULL && P->info.nopol != hapusNopol) {
        P = P->next;
    }

    if (P == NULL) {
        cout << "Data tidak ditemukan!" << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
        dealokasi(P);
    }

    printInfo(L);
    return 0;
}
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


