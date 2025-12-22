#include "BSTree.h"
#include <iostream>
using namespace std;

address alokasiNode(int id, string nama, int stok) {
    address newNode = new Node;
    newNode->info.idProduk = id;
    newNode->info.namaProduk = nama;
    newNode->info.stok = stok;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, int id, string nama, int stok) {
    if (root == Nil) {
        root = alokasiNode(id, nama, stok);
    } else if (id < root->info.idProduk) {
        insertNode(root->left, id, nama, stok);
    } else if (id > root->info.idProduk) {
        insertNode(root->right, id, nama, stok);
    }
}

address searchById(address root, int id) {
    if (root == Nil || root->info.idProduk == id) {
        return root;
    }
    if (id < root->info.idProduk) {
        return searchById(root->left, id);
    } else {
        return searchById(root->right, id);
    }
}

address searchByProduct(address root, string nama) {
    if (root == Nil) return Nil;
    
    if (root->info.namaProduk == nama) return root;
    
    address found = searchByProduct(root->left, nama);
    if (found != Nil) return found;
    
    return searchByProduct(root->right, nama);
}

void deleteNode(address &root, int id) {
    if (root == Nil) return;
    
    if (id < root->info.idProduk) {
        deleteNode(root->left, id);
    } else if (id > root->info.idProduk) {
        deleteNode(root->right, id);
    } else {
        if (root->left == Nil && root->right == Nil) {
            delete root;
            root = Nil;
        } else if (root->left == Nil) {
            address temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == Nil) {
            address temp = root;
            root = root->left;
            delete temp;
        } else {
            address successor = findMin(root->right);
            root->info = successor->info;
            deleteNode(root->right, successor->info.idProduk);
        }
    }
}

void inOrder(address root) {
    if (root == Nil) return;
    inOrder(root->left);
    cout << "ID: " << root->info.idProduk 
        << " | Nama: " << root->info.namaProduk
        << " | Stok: " << root->info.stok << endl;
    inOrder(root->right);
}

void preOrder(address root) {
    if (root == Nil) return;
    cout << "ID: " << root->info.idProduk 
        << " | Nama: " << root->info.namaProduk
        << " | Stok: " << root->info.stok << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root) {
    if (root == Nil) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << "ID: " << root->info.idProduk 
        << " | Nama: " << root->info.namaProduk
        << " | Stok: " << root->info.stok << endl;
}

void deleteTree(address &root) {
    if (root == Nil) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = Nil;
}

address findMin(address root) {
    if (root == Nil) return Nil;
    while (root->left != Nil) {
        root = root->left;
    }
    return root;
}

address findMax(address root) {
    if (root == Nil) return Nil;
    while (root->right != Nil) {
        root = root->right;
    }
    return root;
}