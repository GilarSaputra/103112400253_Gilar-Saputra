# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
1. Rekursif
Rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri, atau suatu fungsi yang memanggil dirinya sendiri [1]. Prosedur dan fungsi adalah sub program yang sangat bermanfaat dalam pemrograman besar. Manfaat penggunaannya antara lain meningkatkan readability, modularity, dan reusability [1].

2. Struktur Data Tree (Pohon)
Tree adalah struktur data yang non-liniar (non-linear data structure), berbeda dari struktur data linear seperti list, stack, dan queue. Tree digambarkan sebagai suatu graph tak berarah terhubung dan tidak mengandung sirkuit [2].
Terminologi Tree:
    1. Anak (Child) dan Orangtua (Parent): B, C, dan D adalah anak-anak simpul A, A adalah orangtua.
    2. Derajat (Degree): Jumlah anak pada simpul tersebut.
    3. Daun (Leaf): Simpul yang berderajat nol (tidak mempunyai anak).
    4. Tinggi (Height) / Kedalaman (Depth): Jumlah maksimum node yang terdapat di cabang tree.

3. Binary Search Tree (BST)
Binary Search Tree adalah Binary Tree yang terurut. Ketentuannya adalah:
    Semua LEFTCHILD harus lebih kecil dari parent-nya.
    Semua RIGHTCHILD harus lebih besar dari parent-nya.
Traversal pada Binary Tree
Tiga metode Traversal pada Binary Tree:
    1. Pre-order: Kunjungi Root, kiri, kanan.
    2. In-order: Kunjungi kiri, R, kanan.
    3. Post-order: Kunjungi kiri, kanan, R.

### A. Materi Praktikum <br/>
...
#### 1.Create Tree - untuk memuat Tree
#### 2.alokasi - mengalokasikan node ke dalam tree 
#### 3.dealokasi - untuk menghapus node
#### 4.Pre-order (Root - Kiri - Kanan)
#### 5.In-order (Kiri - Root - Kanan)
#### 6.Post-order (Kiri - Kanan - Root)

### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Guided 1
stack.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

stack.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

kode ini merupakan struktur data pohon biner yang mengorganisir data secara hierarkis dengan aturan tertentu. Dalam implementasi ini, setiap node menyimpan data bertipe integer dan memiliki dua pointer yang menunjuk ke child kiri dan child kanan. Konsep fundamental dari BST adalah aturan penyusunan data dimana nilai pada child kiri harus lebih kecil dari parent node, sedangkan nilai pada child kanan harus lebih besar dari parent node.

Struktur data yang digunakan cukup sederhana namun powerful, terdiri dari field `angka` untuk menyimpan nilai integer, serta pointer `left` dan `right` untuk membentuk hubungan hierarkis antar node. Implementasi ini menggunakan pendekatan rekursif untuk banyak operasinya, yang sesuai dengan sifat alami struktur pohon. Fungsi `createTree()` digunakan untuk inisialisasi tree kosong, sementara `alokasi()` bertanggung jawab untuk mengalokasikan memori node baru dengan nilai yang ditentukan. Manajemen memori yang baik ditunjukkan dengan adanya fungsi `dealokasi()` yang menangani pembebasan memori secara eksplisit.

**Operasi penyisipan node** (`insertNode`) dilakukan dengan menjaga aturan BST melalui pendekatan rekursif. Jika tree kosong, node baru langsung menjadi root. Jika tidak, algoritma akan membandingkan nilai node baru dengan node current dan bergerak ke subtree kiri jika lebih kecil atau subtree kanan jika lebih besar. Yang menarik, implementasi ini secara elegan menangani kasus duplikat dengan mengabaikan nilai yang sudah ada, sehingga menjaga integritas struktur BST. Untuk operasi penghapusan, fungsi `deleteNode` menangani empat skenario berbeda: node leaf (tanpa child), node dengan satu child kiri, node dengan satu child kanan, dan node dengan dua children. Kasus terakhir ditangani dengan mencari successor menggunakan `mostLeft` dari subtree kanan untuk menggantikan node yang dihapus.

**Fungsi traversal** diimplementasikan dalam tiga varian: `preOrder` (root-kiri-kanan), `inOrder` (kiri-root-kanan), dan `postOrder` (kiri-kanan-root). Traversal in-order particularly penting karena pada BST akan selalu menghasilkan urutan nilai ascending. Implementasi pencarian (`searchByData`) tidak hanya menemukan node target tetapi juga memberikan informasi lengkap tentang parent, sibling, dan children dari node tersebut, memberikan pemahaman yang komprehensif tentang posisi node dalam struktur tree.

**Analisis tree** disediakan melalui fungsi `size` yang menghitung total node menggunakan pendekatan rekursif, dan `height` yang menentukan kedalaman maksimal tree. Fungsi `mostLeft` dan `mostRight` berguna untuk menemukan nilai minimum dan maximum dalam subtree tertentu. Menu interaktif dalam program utama memungkinkan pengguna untuk mengeksplorasi semua fitur ini secara lengkap, dari operasi dasar sampai analisis lanjutan, membuat implementasi ini menjadi tools edukatif yang sangat baik untuk memahami konsep Binary Search Tree secara menyeluruh.

## Unguided 
### 1. soal unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:

```
Type infotype: integer
Type address : pointer to Node
Type Node: <
    info : infotype
    left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address, input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )
```
Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
```
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    return 0;
}
```

### Jawaban
bstree.h
```C++
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

#endif
```

bstree.cpp
```C++
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
```

main.h
```C++
#include <iostream>
#include "bstree.h"

int main() {
    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInOrder(root);
    
    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-11/Laprak-modul-10/assets/output-1.png)<br/>

Program ini merupakan struktur data pohon biner yang dirancang untuk menyimpan dan mengelola data integer secara terurut. Konsep dasar BST diwujudkan melalui aturan dimana setiap node memiliki child kiri dengan nilai lebih kecil dan child kanan dengan nilai lebih besar dari node parent.
    1. Alokasi - Mengalokasikan memori untuk node baru dalam BST
    2. insertNode - Menyisipkan node baru ke dalam BST dengan menjaga sifat binary search tree
    3. findNode - Mencari node dengan nilai tertentu dalam BST
    4. printInOrder -  Mencetak semua nilai dalam tree secara terurut ascending

### 2. soal unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
    ➢ fungsi hitungJumlahNode( root:address ) : integer
        /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
    ➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
        /* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
    ➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
        /* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

```
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungNode(root)<<endl;
    cout<<"total : "<<hitungTotal(root)<<endl;
    return 0;
}
```

### Jawaban
bstree.h
```C++
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

#endif
```

bstree.cpp
```C++
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
    
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    
    if (kiri > kanan) {
        return kiri;
    } else {
        return kanan;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"

int main() {
cout << "Hello World" << endl;
address root = Nil;

insertNode(root,1);
insertNode(root,2);
insertNode(root,6);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
printInOrder(root);
cout<<"\n";

cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;
return 0;
}
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-11/Laprak-modul-10/assets/output-2.png)<br/>

Program ini melanjutkan program pada unguided nomor 1 dimana terdapat penambahan fungsi seperti `hitungKedalaman`, `hitungTotalInfo`, `hitungJumlahNode`

fungsi-fungsi yang digunakan :
    1. Alokasi - Mengalokasikan memori untuk node baru dalam BST
    2. insertNode - Menyisipkan node baru ke dalam BST dengan menjaga sifat binary search tree
    3. findNode - Mencari node dengan nilai tertentu dalam BST
    4. printInOrder -  Mencetak semua nilai dalam tree secara terurut ascending
    5. hitungJumlahNode - Menghitung total jumlah node dalam BST
    6. hitungTotalInfo - Menjumlahkan semua nilai info yang ada dalam BST
    7. hitungKedalaman - Menghitung kedalaman/tinggi maksimal BST


### 3. soal unguided 3
Print tree secara pre-order dan post-order.
![](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-11/Laprak-modul-10/assets/soal-unG3.png)

### Jawaban
stack.h
```C++
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
```

stack.cpp
```C++
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
    
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    
    if (kiri > kanan) {
        return kiri;
    } else {
        return kanan;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);
    
    cout << "In-order: ";
    printInOrder(root);
    cout << endl;
    
    cout << "Pre-order: ";
    printPreOrder(root);
    cout << endl;
    
    cout << "Post-order: ";
    printPostOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;
    
    return 0;
}
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-11/Laprak-modul-10/assets/output-3.png)<br/>

Program ini melanjutkan program nomor 1 dan 2, tetapi bedanya pada soal ini akan menambahkan sebuah print tree berupa pre-order dan post-order 

fungsi-fungsi yang digunakan :
    1. Alokasi - Mengalokasikan memori untuk node baru dalam BST
    2. insertNode - Menyisipkan node baru ke dalam BST dengan menjaga sifat binary search tree
    3. findNode - Mencari node dengan nilai tertentu dalam BST
    4. printInOrder -  Mencetak semua nilai dalam tree secara terurut ascending
    5. hitungJumlahNode - Menghitung total jumlah node dalam BST
    6. hitungTotalInfo - Menjumlahkan semua nilai info yang ada dalam BST
    7. hitungKedalaman - Menghitung kedalaman/tinggi maksimal BST

fungsi yang diminta pada nomor ini :
    1. printpPreOder - Pre-order (Root-Kiri-Kanan), Root selalu diproses pertama sebelum anak-anaknya
    2. printPostOrder - Post-order (Kiri-Kanan-Root), Root selalu diproses terakhir setelah semua anaknya

## Kesimpulan
Kesimpulan ini mencakup dua konsep fundamental dalam struktur data: Rekursif sebagai teknik pemrograman dan Tree sebagai struktur data non-linear, dengan fokus pada implementasi Binary Search Tree (BST).

Rekursif adalah sebuah teknik pemrograman di mana sebuah sub program atau fungsi akan memanggil dirinya sendiri selama kondisi pemanggilan terpenuhi [1].

Tree adalah struktur data non-linear yang digunakan untuk merepresentasikan data secara hierarki, berbeda dengan struktur data linear seperti list, stack, dan queue [2]. Struktur dasar tree dicirikan oleh adanya akar (root) sebagai satu-satunya node tanpa pendahulu, dan node lainnya hanya memiliki satu pendahulu [2].

Fokus implementasi utama dari tree adalah Binary Tree, di mana setiap node hanya dapat mempunyai maksimum dua children [2]. Salah satu jenis Binary Tree yang paling efisien adalah Binary Search Tree (BST) [3].
BST adalah tree yang terurut dengan aturan ketat:
    Semua LEFTCHILD harus memiliki nilai lebih kecil dari parent-nya.
    Semua RIGHTCHILD harus memiliki nilai lebih besar dari parent-nya.

Aturan ini membuat operasi Search menjadi sangat cepat, di mana pencarian nilai yang diinginkan dapat dilakukan secara rekursif dengan membandingkan nilai node saat itu dan mengarahkan pointer ke kiri atau kanan hingga nilai ditemukan atau pointer menunjuk NULL [3]. Operasi Insert juga mengikuti aturan BST yang sama, menyisipkan node baru di Left Subtree atau Right Subtree [3].

Dalam operasi Delete untuk node dengan dua child, node yang dihapus akan digantikan oleh Most-Left node (nilai terkecil di Right Subtree) atau Most-Right node (nilai terbesar di Left Subtree) untuk mempertahankan kriteria BST [3].

3. Traversal
Untuk mengakses semua node di dalam tree secara terstruktur, digunakan operasi Traversal [3]. Tiga metode traversal yang umum adalah:
    - Pre-order: Kunjungi Root (R), lalu Left Subtree (T1), lalu Right Subtree (T2).
    - In-order: Kunjungi Left Subtree (T1), lalu Root (R), lalu Right Subtree (T2).
    - Post-order: Kunjungi Left Subtree (T1), lalu Right Subtree (T2), lalu Root (R).

Secara keseluruhan, pemahaman dan penguasaan teknik Rekursif dan struktur data non-linear seperti Binary Search Tree merupakan dasar yang krusial untuk pengembangan algoritma yang efisien dan sistematis dalam pengolahan data terstruktur.

## Referensi
[1] Febriansyah, M. F., Rhamadani, M., & Sutabri, T. (2025). PERBANDINGAN PEMANFAATAN ALGORITMA REKURSIF DAN ITERATIF DALAM PENYELESAIAN STRUKTUR DATA POHON. Jurnal Manajemen Informatika & Teknologi, 5(1), 46-56.</br>

[2] Mulyana, I. H., & Rifqi, M. (2020). Implementasi Algoritma Binary Tree dan Sequential Searching pada Aplikasi Web Multilevel Marketing. Jurnal Informatika: Jurnal Pengembangan IT, 5(3), 83-87.</br>

[3] Malau, E., & Sirait, H. P. (2021). Implementasi Teknik Binary Search Tree Pada Pencarian Data Penduduk. KAKIFIKOM (Kumpulan Artikel Karya Ilmiah Fakultas Ilmu Komputer), 87-94.


