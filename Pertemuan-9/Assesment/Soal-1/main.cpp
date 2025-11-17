#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {

    List L;
    createList(L);

    Product p1;
    p1.nama = "Pulpen";
    p1.SKU = "A001";
    p1.jumlah = 20;
    p1.HargaSatuan = 2500;
    p1.DiskonPersen = 0;
    p1.address = nullptr;

    Product p2;
    p2.nama = "Buku Tulis";
    p2.SKU = "A002";
    p2.jumlah = 15;
    p2.HargaSatuan = 5000;
    p2.DiskonPersen = 10;
    p2.address = nullptr;

    Product p3;
    p3.nama = "Penghapus";
    p3.SKU = "A003";
    p3.jumlah = 30;
    p3.HargaSatuan = 1500;
    p3.DiskonPersen = 0;
    p3.address = nullptr;

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    cout << endl;
    viewList(L);

    Product hapus;
    deleteFirst(L, hapus);

    cout << endl;
    cout << "=== LIST setlah deleteFirst ===" << endl;
    viewList(L);

    cout << endl;
    cout << "=== Update data pada posisi ke-2 ===" << endl;

    updateAtPosition(L, 2);

    cout << endl;
    cout << "=== Tampilkan list setelah update ===" << endl;
    viewList(L);

    cout << endl;
    cout << "=== Searching Harga Akhir (2000 - 7000) ===" << endl;
    searchByFinalPriceRange(L, 2000, 7000);

    MaxHargaAkhir(L);

    return 0;
}
