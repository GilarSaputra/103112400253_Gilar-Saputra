# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Multi Linked List (MLL) merupakan pengembangan dari struktur data linked list konvensional yang memungkinkan pembentukan hubungan hierarkis antara node.[1] 
MLL terdiri dari dua jenis node yang saling terhubung: node parent dan node child . Setiap node parent dapat memiliki beberapa node child, membentuk hubungan hierarkis satu-ke-banyak. Implementasi ini menggunakan doubly linked list untuk kedua tipe node, dimana setiap node memiliki pointer next dan prev yang memungkinkan traversal maju dan mundur, meningkatkan efisiensi operasi penyisipan dan penghapusan.mplementasi MLL dalam bahasa C++ menggunakan pendekatan doubly linked list yang memungkinkan traversal dua arah, baik dari parent ke child maupun sebaliknya, meningkatkan efisiensi dalam operasi pencarian dan manipulasi data.

Kelebihan utama MLL terletak pada kemampuannya mengelola data kompleks dengan hubungan hierarkis.[1] Operasi dasar pada MLL meliputi inisialisasi, penyisipan, penghapusan, dan traversal.Implementasi doubly linked list pada MLL memungkinkan operasi deleteAfter dengan kompleksitas konstan karena adanya pointer prev yang langsung mengakses node sebelumnya.

### A. Materi Praktikum <br/>
...
#### 1.Mengalokasikan List parent dan list child
#### 2.Membuat node list MLL
#### 3.Menghapus dan Menginsert list kedalam node
#### 4.Pencarian node
#### 5.MLL dengan implementasi Double Linked List


### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Guided 1
stack.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

stack.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
Kode tersebut mengimplementasikan struktur data Multi Linked List (MLL) untuk mengelola menu restoran yang terdiri dari kategori makanan (sebagai parent) dan menu makanan (sebagai child).

1. Inisialisasi dan Alokasi:
    Fungsi `createListInduk()` dan `createListAnak()` menginisialisasi list kosong. `alokasiNodeParent()` dan `alokasiNodeChild()` mengalokasikan memori untuk node baru dan mengisi datanya. Fungsi dealokasi (`dealokasiNodeParent()` dan `dealokasiNodeChild()`) bertugas membebaskan memori yang telah digunakan.

2. Fungsi Prosedur pada Parent:
    Fungsi seperti `insertFirstParent()`, `insertLastParent()`, dan `insertAfterParent()` menambahkan node parent ke dalam list induk. Penghapusan node parent (`deleteFirstParent()`, `deleteLastParent()`, `deleteAfterParent()`) selalu diikuti penghapusan semua child yang terkait, menjaga integritas data. Pencarian (`findParentByID()`) dan pembaruan data (`updateDataParentByID()`) dilakukan berdasarkan ID kategori.

3. Operasi pada Child (Menu Makanan):
    Mirip dengan operasi parent, fungsi `insertFirstChild()`, `insertLastChild()`, dan `insertAfterChild()` menambahkan menu ke dalam list anak milik suatu parent. Penghapusan child hanya memengaruhi node tersebut tanpa mengganggu parent atau child lain. Pencarian (`findChildByID()`) dan pembaruan (`updateDataChildByID()`) dilakukan dengan melintasi semua parent untuk menemukan ID menu yang sesuai.

4. Print dan hapus list:
    `printStrukturMLL()` menampilkan seluruh hierarki data (parent beserta child-nya), sementara `printListInduk()` dan `printListAnak()` menampilkan data secara terpisah. Fungsi `hapusListInduk()` dan `hapusListAnak()` menghapus semua node dalam list, mencegah kebocoran memori.

## Unguided 
### 1. soal unguided 1
Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :

```
Type Struct golonganHewan <
    idGolongan : String
    namaGolongan : String
>
Type Struct dataHewan <
    idHewan : String
    namaHewan : String
    habitat : String
    ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
    bobot : float //dalam kg
>

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct nodeChild

Type Struct nodeChild <
    isidata : dataHewan
    next : NodeChild
    prev : NodeChild
>
Type Struct listChild <
    first : NodeChild
    last : NodeChild
>
Type Struct nodeParent <
    isidata : golonganHewan
    next : NodeParent
    prev : NodeParent
    L_Child : listChild
>
Type Struct listParent <
    first : NodeParent
    last : NodeParent
>

Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)
Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat : String, tail : Boolean, weight : float) : NodeChild
Procedure deallocNodeParent(input/output NParent : NodeParent)
Procedure deallocNodeChild(input/output NChild : NodeChild)
Procedure insertFirstParent(input/output LParent : listParent, newNParent : NodeParent)
Procedure insertLastParent(input/output LParent : listParent, newNParent : NodeParent)
Procedure deleteFirstParent(input/output LParent : listParent)
Procedure deleteAfterParent(input/output LParent : listParent, NPrev : NodeParent)
Procedure insertFirstChild(input/output LChild : listChild, newNChild : NodeChild)
Procedure insertLastChild(input/output LChild : listChild, newNChild : NodeChild)
Procedure deleteFirstChild(input/output LChild : listChild)
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild)
Procedure printMLLStructure(input/output LParent : listParent)
Procedure deleteListChild(input/output LChild : listChild)
```
Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.

Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya seperti ini :

Keterangan isi data setiap node :
❖ List Parent :
1)  idGolongan : G001
    namaGolongan : Aves
2)  idGolongan : G002
    namaGolongan : Mamalia
3)  idGolongan : G003
    namaGolongan : Pisces
4)  idGolongan : G004
    namaGolongan : Amfibi
5)  idGolongan : G005
    namaGolongan : Reptil

❖ List Child G001 :
1)  idHewan : AV001
    namaHewan : Cendrawasih
    habitat : Hutan
    ekor : True
    bobot : 0,3
2)  idHewan : AV002
    namaHewan : Bebek
    habitat : Air
    ekor : True
    bobot : 2

❖ List Child G002 :
1)  idHewan : M001
    namaHewan : Harimau
    habitat : Hutan
    ekor : True
    bobot : 200
2)  idHewan : M003
    namaHewan : Gorila
    habitat : Hutan
    ekor : False
    bobot : 160
3)  idHewan : M002
    namaHewan : Kucing
    habitat : Darat
    ekor : True
    bobot : 4

❖ List Child G004 :
1)  idHewan : AM001
    namaHewan : Kodok
    habitat : Sawah
    ekor : False
    bobot : 0,2

Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur printMLLStructure().

### Jawaban
MultiLL.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent kosong" << endl;
    } else {
        NodeParent temp = LParent.first;
        LParent.first = LParent.first->next;
        if (LParent.first != NULL) {
            LParent.first->prev = NULL;
        } else {
            LParent.last = NULL;
        }
        deleteListChild(temp->L_Child);
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeParent toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    deleteListChild(toDelete->L_Child);
    deallocNodeParent(toDelete);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) {
        cout << "List Child kosong" << endl;
    } else {
        NodeChild temp = LChild.first;
        LChild.first = LChild.first->next;
        if (LChild.first != NULL) {
            LChild.first->prev = NULL;
        } else {
            LChild.last = NULL;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeChild toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    deallocNodeChild(toDelete);
}

void printMLLStructure(listParent &LParent) {
    nodeParent* P = LParent.first;
    int parentCount = 1;
    
    while (P != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child) == true) {
            cout << "(tidak ada child)" << endl;
        } else {
            nodeChild* C = P->L_Child.first;
            int childCount = 1;
            
            while (C != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                
                cout << "    Ekor : ";
                if (C->isidata.ekor == true) {
                    cout << "1";
                } else {
                    cout << "0";
                }
                cout << endl;
                
                cout << "    Bobot : " << C->isidata.bobot << endl;
                
                C = C->next;
                childCount = childCount + 1;
            }
        }
        
        P = P->next;
        parentCount = parentCount + 1;
        cout << "-------------------------" << endl;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}
```

main.h
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, P1);
    insertLastParent(LParent, P2);
    insertLastParent(LParent, P3);
    insertLastParent(LParent, P4);
    insertLastParent(LParent, P5);

    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1);
    insertLastChild(P1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    NodeChild C4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    NodeChild C5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C3);
    insertLastChild(P2->L_Child, C4);
    insertLastChild(P2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C6);

    cout << "=== Struktur Multi Linked List Setelah INSERT ===" << endl;
    printMLLStructure(LParent);

    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-12/Laprak-modul-13/assets/output-1.png)<br/>

Kode ini mengimplementasikan struktur data Multi Linked List (MLL) untuk mengklasifikasikan data hewan berdasarkan golongannya.  node parent (golongan hewan) dan node child (data hewan spesifik). Menggunakan konsep Double Link List sehingga terdapat next dan prev.
Penjelasan struktur pada program :
    1. golonganHewan: Menyimpan ID dan nama golongan (misal: Aves, Mamalia).
    2. dataHewan: Menyimpan detail hewan (ID, nama, habitat, keberadaan ekor, bobot).
    3. nodeParent: Node untuk golongan, dilengkapi pointer ke list child dan pointer next/prev.
    4. nodeChild: Node untuk data hewan, dengan pointer next/prev.
    5. listParent dan listChild: Struktur pengelola list dengan pointer first dan last.

Penjelasan Fungsi Fungsi pada program :
1. `isEmptyParent()` dan `isEmptyChild()`
    Fungsi ini bertujuan untuk memeriksa apakah list parent atau child kosong. Mengembalikan nilai true jika pointer first bernilai NULL, menandakan tidak ada elemen dalam list.

2. `createListParent()` dan `createListChild()`
    Berfungsi untuk menginisialisasi list kosong dengan mengatur pointer first dan last menjadi NULL.

3. `allocNodeParent()`
    Mengalokasikan memori untuk node parent baru, mengisi data golongan (ID dan nama), serta menginisialisasi list child kosong untuk node tersebut.

4. `allocNodeChild()`
    Mengalokasikan memori untuk node child baru dengan mengisi seluruh atribut data hewan (ID, nama, habitat, ekor, bobot).

5. `deallocNodeParent()` dan `deallocNodeChild()`
    Membebaskan memori yang dialokasikan untuk node parent atau child menggunakan operator delete.

6. `insertFirstParent()`
    Menyisipkan node parent baru di awal list parent. Jika list kosong, node menjadi satu-satunya elemen. Jika tidak, node baru ditautkan sebelum node pertama saat ini.

7. `insertLastParent()`
    Menambahkan node parent baru di akhir list parent. Untuk list kosong. Untuk list berisi, node baru ditautkan setelah node terakhir.

8. `deleteFirstParent()`
    Menghapus node parent pertama dari list. Sebelum dealokasi, semua child dalam node tersebut dihapus menggunakan deleteListChild().

9. `deleteAfterParent()`
    Menghapus node parent yang berada setelah node tertentu (NPrev).

10. `insertFirstChild()`
    Menambahkan node child baru di awal list child milik suatu parent.

11. `insertLastChild()`
    Menyisipkan node child baru di akhir list child.

12. `deleteFirstChild()`
    Menghapus node child pertama dari list child. Pointer first diperbarui.

13. `deleteAfterChild()`
    Menghapus node child yang terletak setelah node tertentu (NPrev).

14. printMLLStructure()
    Menampilkan seluruh struktur MLL.

15. deleteListChild()
    Menghapus semua node dalam list child.

### 2. soal unguided 2
Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.

### Jawaban
MultiLL.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent kosong" << endl;
    } else {
        NodeParent temp = LParent.first;
        LParent.first = LParent.first->next;
        if (LParent.first != NULL) {
            LParent.first->prev = NULL;
        } else {
            LParent.last = NULL;
        }
        deleteListChild(temp->L_Child);
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeParent toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    deleteListChild(toDelete->L_Child);
    deallocNodeParent(toDelete);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) {
        cout << "List Child kosong" << endl;
    } else {
        NodeChild temp = LChild.first;
        LChild.first = LChild.first->next;
        if (LChild.first != NULL) {
            LChild.first->prev = NULL;
        } else {
            LChild.last = NULL;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeChild toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    deallocNodeChild(toDelete);
}

void printMLLStructure(listParent &LParent) {
    nodeParent* P = LParent.first;
    int parentCount = 1;
    
    while (P != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child) == true) {
            cout << "(tidak ada child)" << endl;
        } else {
            nodeChild* C = P->L_Child.first;
            int childCount = 1;
            
            while (C != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                
                cout << "    Ekor : ";
                if (C->isidata.ekor == true) {
                    cout << "1";
                } else {
                    cout << "0";
                }
                cout << endl;
                
                cout << "    Bobot : " << C->isidata.bobot << endl;
                
                C = C->next;
                childCount = childCount + 1;
            }
        }
        
        P = P->next;
        parentCount = parentCount + 1;
        cout << "-------------------------" << endl;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    cout << "=== Hasil Pencarian Hewan ===" << endl;
    if (tail == true) {
        cout << "Hewan dengan EKOR: TRUE" << endl;
    } else {
        cout << "Hewan dengan EKOR: FALSE" << endl;
    }
    cout << "=============================" << endl;
    
    nodeParent* P = LParent.first;
    bool found = false;
    
    while (P != NULL) {
        nodeChild* C = P->L_Child.first;
        
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                found = true;
                
                cout << "ID Golongan : " << P->isidata.idGolongan << endl;
                cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                cout << "ID Hewan : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                
                cout << "Ekor : ";
                if (C->isidata.ekor == true) {
                    cout << "TRUE";
                } else {
                    cout << "FALSE";
                }
                cout << endl;
                
                cout << "-------------------------" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
    
    if (found == false) {
        cout << "Tidak ditemukan hewan dengan ekor ";
        if (tail == true) {
            cout << "TRUE";
        } else {
            cout << "FALSE";
        }
        cout << endl;
    }
}
```

main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, P1);
    insertLastParent(LParent, P2);
    insertLastParent(LParent, P3);
    insertLastParent(LParent, P4);
    insertLastParent(LParent, P5);

    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1);
    insertLastChild(P1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    NodeChild C4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    NodeChild C5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C3);
    insertLastChild(P2->L_Child, C4);
    insertLastChild(P2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C6);

    cout << "=== Struktur Multi Linked List Setelah INSERT ===" << endl;
    printMLLStructure(LParent);

    cout << endl;
    searchHewanByEkor(LParent, false);

    return 0;
}
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-12/Laprak-modul-13/assets/output-2.png)<br/>

Program ini merupakan program yang di lanjutkan dari kode program unguided 1, dimana fungsi yang digunakan sama, tetapi terdapat penambahan 1 fungsi yaitu `searchHewanByEkor()` dimana ini berfungsi untuk mencari sebuah hewan berdasarkan ekor.
Dari soal kita tahu program menginginkan agar mengeprint  hewan hewan yang tidak memiliki ekor dengan menelusuri list child pada setiap parent.

### 3. soal unguided 3
Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :

### Jawaban
MultiLL.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent kosong" << endl;
    } else {
        NodeParent temp = LParent.first;
        LParent.first = LParent.first->next;
        if (LParent.first != NULL) {
            LParent.first->prev = NULL;
        } else {
            LParent.last = NULL;
        }
        deleteListChild(temp->L_Child);
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeParent toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    deleteListChild(toDelete->L_Child);
    deallocNodeParent(toDelete);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) {
        cout << "List Child kosong" << endl;
    } else {
        NodeChild temp = LChild.first;
        LChild.first = LChild.first->next;
        if (LChild.first != NULL) {
            LChild.first->prev = NULL;
        } else {
            LChild.last = NULL;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeChild toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    deallocNodeChild(toDelete);
}

void printMLLStructure(listParent &LParent) {
    nodeParent* P = LParent.first;
    int parentCount = 1;
    
    while (P != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child) == true) {
            cout << "(tidak ada child)" << endl;
        } else {
            nodeChild* C = P->L_Child.first;
            int childCount = 1;
            
            while (C != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                
                cout << "    Ekor : ";
                if (C->isidata.ekor == true) {
                    cout << "1";
                } else {
                    cout << "0";
                }
                cout << endl;
                
                cout << "    Bobot : " << C->isidata.bobot << endl;
                
                C = C->next;
                childCount = childCount + 1;
            }
        }
        
        P = P->next;
        parentCount = parentCount + 1;
        cout << "-------------------------" << endl;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    nodeParent* P = LParent.first;
    int nomorParent = 1;
    bool adaHasil = false;
    
    while (P != NULL) {
        nodeChild* C = P->L_Child.first;
        int nomorChild = 1;
        
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                adaHasil = true;
                
                cout << "Data ditemukan pada list anak dari node parent ";
                cout << P->isidata.namaGolongan << " pada posisi ke-" << nomorChild << "!" << endl;
                cout << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << nomorChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "---" << endl;
                cout << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << nomorParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "---" << endl;
                cout << endl;
                cout << endl;
            }
            C = C->next;
            nomorChild = nomorChild + 1;
        }
        P = P->next;
        nomorParent = nomorParent + 1;
    }
    
    if (adaHasil == false) {
        cout << "Tidak ada hewan yang ditemukan dengan kriteria pencarian." << endl;
    }
}
```

main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, P1);
    insertLastParent(LParent, P2);
    insertLastParent(LParent, P3);
    insertLastParent(LParent, P4);
    insertLastParent(LParent, P5);

    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1);
    insertLastChild(P1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    NodeChild C4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    NodeChild C5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C3);
    insertLastChild(P2->L_Child, C4);
    insertLastChild(P2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C6);

    cout << "=== Struktur Multi Linked List Setelah INSERT ===" << endl;
    printMLLStructure(LParent);

    cout << endl;

    cout << "\n=== Struktur Multi Linked List Setelah DELETE G004 ===" << endl;
    printMLLStructure(LParent);

    return 0;
}
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-12/Laprak-modul-13/assets/output-3.png)<br/>

Untuk Unguided 3 hampir, fungsi yang ada pada program sama dengan unguided 1. Dimana program akan melakukan penghapusan node "G004". Seluruh data yang ada berupa list parent dan list child akan di hapus.

## Kesimpulan
Berdasarkan implementasi dan analisis yang telah dilakukan, dapat disimpulkan bahwa Multi Linked List merupakan struktur data yang efektif untuk mengelola data hierarkis seperti sistem klasifikasi hewan. Implementasi menggunakan doubly linked list memungkinkan operasi penyisipan dan penghapusan dengan efisiensi tinggi, khususnya untuk operasi pada posisi tertentu yang diketahui. Hasil pengujian menunjukkan bahwa struktur MLL dapat merepresentasikan hubungan golongan-hewan dengan baik, dimana setiap golongan (parent) dapat memiliki banyak hewan (child) sesuai karakteristik biologisnya. Keberhasilan implementasi terletak pada manajemen memori yang tepat, dimana setiap penghapusan node parent diikuti dengan pembebasan memori semua node child-nya, mencegah kebocoran memori.[1]

## Referensi
[1] Erkamim, E., Abdurrohim, I., Yuliyanti, S., Karim, R., Rahman, A., Admira, T. M. A., & Ridwan, A. (2024). Buku Ajar Algoritma dan Struktur Data. PT. Sonpedia Publishing Indonesia.</br>


