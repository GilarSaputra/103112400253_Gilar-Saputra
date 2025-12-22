#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

typedef struct Node* address;

struct Product {
    int idProduk;
    string namaProduk;
    int stok;
};

struct Node {
    Product info;
    address left;
    address right;
};

address alokasiNode(int id, string nama, int stok);
void insertNode(address &root, int id, string nama, int stok);
address searchById(address root, int id);
address searchByProduct(address root, string nama);
void deleteNode(address &root, int id);
void deleteTree(address &root);
address findMin(address root);
address findMax(address root);
void inOrder(address root);
void preOrder(address root);
void postOrder(address root);

#endif