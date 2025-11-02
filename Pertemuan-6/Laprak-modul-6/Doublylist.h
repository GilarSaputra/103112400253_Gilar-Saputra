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
