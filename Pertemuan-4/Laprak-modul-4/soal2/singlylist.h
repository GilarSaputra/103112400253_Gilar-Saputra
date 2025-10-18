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
