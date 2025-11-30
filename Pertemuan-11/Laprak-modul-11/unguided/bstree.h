#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

#include <iostream>
using namespace std;

// Soal Nomor 1
typedef int infotype;
typedef struct Node* address;
struct Node {
    infotype info;
    address left, right; 
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInOrder(address root);

// Soal 2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// Soal 3
void printPreOrder(address root);
void printPostOrder(address root);

#endif