#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <iostream>
using namespace std;

// BAGAIN A
struct Node;
struct Product {
    string nama;
    string SKU;
    int jumlah;
    float HargaSatuan, DiskonPersen;
    Node* address;
};

struct Node {
    Product info;
    Node* next;
};

typedef Node* address;

struct List {
    address head;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address &addr);
void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);
void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);
void updateAtPosition(List &L, int posisi);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

// BAGIAN B
void MaxHargaAkhir(List L);
#endif
