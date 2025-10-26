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

// Soal Nomor 1
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodeprev);

// soal Nomor 2
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, int nilaiMin);

// Soal Nomor 3
void penjumlahanList(linkedList L);
void penguranganList(linkedList L);
void perkalianList(linkedList L);

#endif
