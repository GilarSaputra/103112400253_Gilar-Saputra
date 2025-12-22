#include "BSTree.h"
#include <iostream>
using namespace std;

int main() {
    address root = Nil;

    cout << "=======================" << endl;
    cout << "ID Produk | Nama Produk    | Stok" << endl;
    cout << "----------------------------------" << endl;
    cout << "50        | Monitor LED    | 10" << endl;
    cout << "30        | Keyboard RGB   | 20" << endl;
    cout << "70        | Mouse Gaming   | 15" << endl;
    cout << "20        | Kabel HDMI     | 50" << endl;
    cout << "40        | Headset 7.1    | 12" << endl;
    cout << "60        | Webcam HD      | 8" << endl;
    cout << "80        | Speaker BT     | 5" << endl;
    
    insertNode(root, 50, "Monitor LED", 10);
    insertNode(root, 30, "Keyboard RGB", 20);
    insertNode(root, 70, "Mouse Gaming", 15);
    insertNode(root, 20, "Kabel HDMI", 50);
    insertNode(root, 40, "Headset 7.1", 12);
    insertNode(root, 60, "Webcam HD", 8);
    insertNode(root, 80, "Speaker BT", 5);
    
    cout << "\n inOrder():" << endl;
    cout << "-------------" << endl;
    inOrder(root);
    
    cout << "\n preOrder():" << endl;
    cout << "--------------" << endl;
    preOrder(root);
    
    cout << "\n postOrder():" << endl;
    cout << "---------------" << endl;
    postOrder(root);
    
    cout << "\n Cari ID barang 40" << endl;
    cout << "==================" << endl;
    address outSrcID1 = searchById(root, 40);
    if (outSrcID1 != Nil) {
        cout << "Ditemukan: ID: " << outSrcID1->info.idProduk 
            << ", Nama: " << outSrcID1->info.namaProduk
            << ", Stok: " << outSrcID1->info.stok << endl;
    } else {
        cout << "Barang Tidak ditemukan" << endl;
    }
    
    cout << "\n Cari ID barang 99" << endl;
    cout << "==================" << endl;
    address outSrcID2 = searchById(root, 99);
    if (outSrcID2 != Nil) {
        cout << "Ditemukan: ID: " << outSrcID2->info.idProduk 
            << ", Nama: " << outSrcID2->info.namaProduk
            << ", Stok: " << outSrcID2->info.stok << endl;
    } else {
        cout << "Barang Tidak ditemukan" << endl;
    }
    
    cout << "\n Cari produk Webcam HD " << endl;
    cout << "=================================" << endl;
    address srcWebcam = searchByProduct(root, "Webcam HD");
    if (srcWebcam != Nil) {
        cout << "Ditemukan: ID: " << srcWebcam->info.idProduk 
            << ", Nama: " << srcWebcam->info.namaProduk
            << ", Stok: " << srcWebcam->info.stok << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }
    
    cout << "\n Cari produk Printer" << endl;
    cout << "===============================" << endl;
    address srcPrinter = searchByProduct(root, "Printer");
    if (srcPrinter != Nil) {
        cout << "Ditemukan: ID: " << srcPrinter->info.idProduk 
            << ", Nama: " << srcPrinter->info.namaProduk
            << ", Stok: " << srcPrinter->info.stok << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }
    
    cout << "\n findMin:" << endl;
    cout << "-------------" << endl;
    address minNode = findMin(root);
    if (minNode != Nil) {
        cout << "ID terkecil: " << minNode->info.idProduk 
            << ", Nama: " << minNode->info.namaProduk
            << ", Stok: " << minNode->info.stok << endl;
    } else {
        cout << "kosong" << endl;
    }
    
    cout << "\n findMax:" << endl;
    cout << "-------------" << endl;
    address maxNode = findMax(root);
    if (maxNode != Nil) {
        cout << "ID terbesar: " << maxNode->info.idProduk 
            << ", Nama: " << maxNode->info.namaProduk
            << ", Stok: " << maxNode->info.stok << endl;
    } else {
        cout << "kosong" << endl;
    }
    
    deleteNode(root, 20);

    cout << "\n inOrder" << endl;
    cout << "=============" << endl;
    inOrder(root);
    
    deleteNode(root, 30);
    
    cout << "\n inOrder" << endl;
    cout << "==============" << endl;
    inOrder(root);
    
    deleteNode(root, 50);
    
    cout << "\n inOrder" << endl;
    cout << "==============" << endl;
    inOrder(root);
    
    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree telah dihapus." << endl;
    

    cout << "\n inOrder" << endl;
    cout << "==============" << endl;
    inOrder(root);
    if (root == Nil) {
        cout << "(Tree kosong)" << endl;
    }
        
    return 0;
}