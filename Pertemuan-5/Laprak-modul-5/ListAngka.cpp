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