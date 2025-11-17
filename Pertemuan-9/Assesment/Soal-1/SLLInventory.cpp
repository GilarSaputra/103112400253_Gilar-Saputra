#include "SLLInventory.h"

// BAGIAN A
bool isEmpty(List L){
    return (L.head == nullptr);
}

void createList(List &L){
    L.head = nullptr;
}

address allocate(Product P){
    address nodebaru = new Node;

    nodebaru->info = P;
    nodebaru->next = nullptr;
    nodebaru->info.address = nodebaru;
    return nodebaru;
}

void deallocate(address &addr){
    addr = nullptr;
    delete addr;
}

void insertFirst(List &L, Product P){
    address nodebaru = allocate(P);
    nodebaru->next = L.head;
    L.head = nodebaru;
}

void insertLast(List &L, Product P){
    address nodebaru = allocate(P);

    if (isEmpty(L)) {
        L.head = nodebaru;
    } else {
        address temp = L.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodebaru;
    }
}

void insertAfter(List &L, address Q, Product P){
    if (Q != nullptr) {
        address nodebaru = allocate(P);
        nodebaru->next = Q->next;
        Q->next = nodebaru;
    }
}

void deleteFirst(List &L, Product &P){
    if (!isEmpty(L)) {
        address del = L.head;
        P = del->info;
        L.head = del->next;
        deallocate(del);
    }
}

void deleteLast(List &L, Product &P){
    if (!isEmpty(L)) {

        if (L.head->next == nullptr) {
            P = L.head->info;
            deallocate(L.head);
            L.head = nullptr;
        } else {
            address temp = L.head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            address del = temp->next;
            P = del->info;
            temp->next = nullptr;
            deallocate(del);
        }
    }
}

void deleteAfter(List &L, address Q, Product &P){
    if (Q != nullptr && Q->next != nullptr) {
        address del = Q->next;
        P = del->info;
        Q->next = del->next;
        deallocate(del);
    }
}

void updateAtPosition(List &L, int posisi){
    address temp = L.head;
    int index = 1;

    while (temp != nullptr && index < posisi) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak ditemukan." << endl;
        return;
    }

    Product Pbaru;

    cout << "Masukkan data baru:" << endl;
    cout << "Nama: ";
    cin >> Pbaru.nama;

    cout << "SKU: ";
    cin >> Pbaru.SKU;

    cout << "Jumlah: ";
    cin >> Pbaru.jumlah;

    cout << "Harga Satuan: ";
    cin >> Pbaru.HargaSatuan;

    cout << "Diskon Persen: ";
    cin >> Pbaru.DiskonPersen;

    temp->info = Pbaru;
    temp->info.address = temp;
}



void viewList(List L){
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address temp = L.head;
    while (temp != nullptr) {
        Product P = temp->info;
        cout << "Nama: " << P.nama << endl;
        cout << "SKU: " << P.SKU << endl;
        cout << "Jumlah: " << P.jumlah << endl;
        cout << "HargaSatuan: " << P.HargaSatuan << endl;
        cout << "DiskonPersen: " << P.DiskonPersen << endl;
        cout << endl;
        temp = temp->next;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice){
    address temp = L.head;

    while (temp != nullptr) {
        float finalPrice = temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

        if (finalPrice >= minPrice && finalPrice <= maxPrice) {
            cout << temp->info.nama
                << "Harga Akhir: " << finalPrice
                << endl;
        }

        temp = temp->next;
    }
}

// BAGIAN B
void MaxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List kosong. Tidak dapat mencari harga maksimum." << endl;
        return;
    }

    address current = L.head;
    float maxPrice = -1.0; 

    while (current != nullptr) {
        float finalPrice = current->info.HargaSatuan * (1.0 - current->info.DiskonPersen / 100.0);
        
        if (finalPrice > maxPrice) {
            maxPrice = finalPrice;
        }
        current = current->next;
    }

    cout << "\n=== Hasil Pencarian Produk Harga Akhir Maksimum ===" << endl;
    cout << "Harga Akhir Maksimum: " << maxPrice << endl;

    current = L.head;
    int position = 1; 
    bool found = false;

    while (current != nullptr) {
        float finalPrice = current->info.HargaSatuan * (1.0 - current->info.DiskonPersen / 100.0);

        if (finalPrice == maxPrice) {
            cout << "Posisi : " << position << endl;
            cout << "Nama : " << current->info.nama << endl;
            cout << "SKU : " << current->info.SKU << endl;
            cout << "Jumlah : " << current->info.jumlah << endl;
            cout << "Harga Satuan : " << current->info.HargaSatuan << endl;
            cout << "Diskon Persen : " << current->info.DiskonPersen << endl;
            cout << "Harga Akhir : " << finalPrice << endl;
            found = true;
        }

        current = current->next;
        position++;
    }
}
