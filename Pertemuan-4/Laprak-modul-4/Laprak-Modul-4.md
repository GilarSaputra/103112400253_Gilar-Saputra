# <h1 align="center">Laporan Praktikum Modul 4 - Abstract Data Type (ADT)</h1>
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


## Guided 

### 1. Singly Linked list 1

```C++
//KODE <list.h> Start 
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};
bool isEmpety(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);

#endif
//KODE <list.h> End 

//KODE <list.cpp> Start
#include "list.h"
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

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
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

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
//KODE <list.cpp> End

//KODE <main.cpp> Start
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC);
    insertAfter(List, nodeD);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
//KODE <main.cpp> End
```
Program di atas merupakan implementasi struktur data singly linked list untuk menyimpan data mahasiswa yang terdiri dari nama, NIM, dan umur. File list.h berisi deklarasi tipe data dan fungsi untuk membuat, menambah, menampilkan, serta menghapus node dalam list. File list.cpp mengimplementasikan fungsi-fungsi tersebut. Untuk menampilkan seluruh isi list. Pada main.cpp, beberapa data mahasiswa dialokasikan dan disisipkan ke dalam list

### 2. Singly Linked List 2

```C++
//KODE <list.h> Start 
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);
#endif
//KODE <list.h> End 

//KODE <list.cpp> Start
#include "list.h"
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

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
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
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
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
    cout << "List sudah terhapus!" << endl;
}
//KODE <list.cpp> End

//KODE <main.cpp> Start
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

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
//KODE <main.cpp> End

```
Program di atas berfungsi untuk mengelola data mahasiswa menggunakan struktur data linked list. Program dapat menambah, menampilkan, menghitung jumlah, dan menghapus data mahasiswa secara dinamis. Setiap data berisi nama, NIM, dan umur. Melalui fungsi-fungsi seperti insertFirst, insertLast, dan deleteList, program menunjukkan cara kerja dasar linked list dalam menyimpan dan memanipulasi data secara berurutan di memori.

## Unguided 

### 1. soal unguided 1
(https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-4/Laprak-modul-4/assets/soal1.png)
(https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-4/Laprak-modul-4/assets/soal1-2.png)

```C++
//KODE <singlylist.h> Start 
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist;          
typedef Elmlist* address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &p);
void printInfo(List L);
void insertFirst(List &L, address p);

#endif
//KODE <singlylist.h> End 

//KODE <singlylist.cpp> Start
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address p = new Elmlist;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = nullptr;
}

void printInfo(List L) {
    address p = L.First;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(List &L, address p) {
    p->next = L.First;
    L.First = p;
}
//KODE <singlylist.cpp> End

//KODE <main.cpp> Start
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = nullptr;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
//KODE <main.cpp> End
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-4/Laprak-modul-4/assets/output-1.png)


Kode di atas adalah kode yang berfungsi 

### 2. soal unguided 2
(https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-4/Laprak-modul-4/assets/soal2.png)


```C++
//KODE <singlylist.h> Start 
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist;          
typedef Elmlist* address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &p);
void printInfo(List L);
void insertFirst(List &L, address p);

void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
void deleteAfter(List &L, address prec, address &p);
int nbList(List L);
void deleteList(List &L);

#endif
//KODE <singlylist.h> End 

//KODE <singlylist.cpp> Start
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address p = new Elmlist;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = nullptr;
}

void printInfo(List L) {
    address p = L.First;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(List &L, address p) {
    p->next = L.First;
    L.First = p;
}

void deleteFirst(List &L, address &p) {
    if (L.First != nullptr) {
        p = L.First;
        L.First = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteLast(List &L, address &p) {
    if (L.First == nullptr) {
        p = nullptr;
    } else if (L.First->next == nullptr) {
        p = L.First;
        L.First = nullptr;
    } else {
        address q = L.First;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

void deleteAfter(List &L, address prec, address &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

int nbList(List L) {
    int count = 0;
    address p = L.First;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    address p;
    while (L.First != nullptr) {
        deleteFirst(L, p);
        dealokasi(p);
    }
}
//KODE <singlylist.cpp> End

//KODE <main.cpp> Start
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, Pdel, Prec;

    CreateList(L);

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    deleteFirst(L, Pdel); 
    dealokasi(Pdel);

    deleteLast(L, Pdel);  
    dealokasi(Pdel);

    Prec = L.First;
    while (Prec != nullptr && Prec->info != 12) {
        Prec = Prec->next;
    }
    deleteAfter(L, Prec, Pdel);
    dealokasi(Pdel);

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
//KODE <main.cpp> End

### Output Unguided 2:
```

![Screenshot Output Unguided 2] (https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-4/Laprak-modul-4/assets/output-2.png)

Kode di atas adalah kode yang berfungsi 

## Kesimpulan
Pada praktikum Modul 3 ini, mahasiswa mempelajari materi tentang Abstract Data Type (ADT)

konsep fundamental Abstract Data Type (ADT) telah  dipahami dan diimplementasikan, terutama melalui pemisahan antara spesifikasi (.h) dan realisasi (.cpp), seperti yang ditunjukkan pada implementasi ADT Pelajaran[2]. Melalui praktikum ini, praktikan dapat mendefinisikan tipe data baru (struct) dan mengelompokkannya dengan operasi dasar (primitif) yang relevan, menjadikan kode program lebih modular dan reusable. Selain ADT, praktikum juga mencakup penerapan struktur data kolektif, yaitu Array 1D untuk menyimpan sekumpulan objek ADT Mahasiswa dan Array 2D untuk memanipulasi data matriks, serta penggunaan Pointer untuk operasi penukaran nilai variabel secara langsung melalui alamat memorinya, menegaskan pemahaman tentang pengelolaan data dan memori dalam konteks pemrograman prosedural C++[2].

## Referensi
[1] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>
[2] Fitriyani, D., dkk. (2022). Algoritma dan Pemrograman dalam Bahasa C++. UMSIDA Press. Diakses dari https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4/759

