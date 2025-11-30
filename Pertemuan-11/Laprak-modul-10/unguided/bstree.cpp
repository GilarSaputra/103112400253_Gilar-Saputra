#include <iostream>
#include "bstree.h"

using namespace std;

address alokasi(infotype x) {
    address newNode = new Node;
    newNode->info = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(address &root, infotype x) {
    if (root == nullptr) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    }else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInOrder(address root) {
    if(root == Nil){
        return;
    }
    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

void printPreOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(address root){ 
    if(root == Nil){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->info << " - ";
}

int hitungJumlahNode(address root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == nullptr) {
        return start;
    }
    
    int totalKiri = hitungTotalInfo(root->left, start);
    int totalKanan = hitungTotalInfo(root->right, start);
    
    return root->info + totalKiri + totalKanan;
}

int hitungKedalaman(address root, int start) {
    if (root == nullptr) {
        return start;
    }
    
    // Hitung kedalaman kedua subtree
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    
    // Kembalikan yang lebih besar
    if (kiri > kanan) {
        return kiri;
    } else {
        return kanan;
    }
}