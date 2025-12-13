# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Graf adalah struktur data yang terdiri dari kumpulan simpul (vertex) dan himpunan sisi (edge) yang menghubungkan pasangan simpul. Graf dipakai untuk memodelkan relasi antar objek nyata seperti jaringan jalan, jaringan komputer, relasi sosial, dan lain-lain.[2] Konsep ini dibahas secara komprehensif dalam literatur pengantar struktur data berbahasa Indonesia dan makalah aplikasi graf.

Graph dapat dibedakan menjadi beberapa jenis, di antaranya:
    1. Graph Berarah (Directed Graph) : Merupakan Graph di mana setiap edge memiliki arah, yang menunjukkan koneksi dari satu node ke node tertentu lainnya. Dalam Graph berarah, jika node A terhubung ke node B, belum tentu node B terhubung kembali ke node A.[2]
    2. Graph Tidak Berarah (Undirected Graph) : Merupakan Graph di mana setiap node memiliki edge yang menghubungkannya ke node lain tanpa arah. Artinya, jika node A terhubung dengan node B, secara otomatis terbentuk panah bolak-balik (keterhubungan) dari A ke B dan B ke A.[2]

Dalam implementasi program, Graph dapat direpresentasikan dengan beberapa cara, dua yang paling umum adalah Matriks Ketetanggaan (Adjacency Matrices) dan Multi Linked List.[1]

Dua metode dasar yang umum digunakan untuk mengunjungi node-node dalam Graph adalah:
    - A. Breadth First Search (BFS)
        BFS bekerja dengan mengunjungi root (kedalaman 0), kemudian semua node di kedalaman 1, lalu kedalaman 2, dan seterusnya. Kunjungan pada setiap level dimulai dari kiri ke kanan. Algoritma ini menggunakan struktur data Queue (Antrian) untuk mengelola node yang akan dikunjungi.

    - B. Depth First Search (DFS)
        DFS bekerja dengan mengunjungi root, kemudian secara rekursif bergerak sedalam mungkin ke subtree dari node tersebut. Algoritma ini menggunakan struktur data Stack (Tumpukan) untuk mengelola node yang akan dikunjungi.

### A. Materi Praktikum <br/>
...
#### 1. Create Graph
#### 2. Insert dan delete Graph
#### 2. Print BFS dan DFS


### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Guided 1
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge
{
    adrNode Node;
    adrEdge Next;
};

struct Graph
{
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode alokasiNode(infoGraph data);
adrEdge alokasiEdge(adrNode nodeTujuan);
void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode Node1, adrNode Node2);
void DeleteNode(Graph &G, infoGraph X);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```

graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

// prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G)
{
    G.First = NULL;
}

// alokasi Node baru
adrNode alokasiNode(infoGraph data)
{
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; // isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

// alokasi Edge baru
adrEdge alokasiEdge(adrNode nodeTujuan)
{
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

// Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data)
{
    adrNode nodeBaru = alokasiNode(data);
    if (G.First == NULL)
    {
        G.First = nodeBaru;
    }
    else
    {
        // konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL)
        {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

// function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data)
{
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL)
    {
        if (nodeBantu->info == data)
        {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

// prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2)
{
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL)
    {
        // Hubungkan node1 ke node2
        adrEdge Edge1 = alokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        // Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = alokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}

// prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2)
{
    if (node1 != NULL && node2 != NULL)
    {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        // Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2)
        {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL)
        { // jika Edge ditemukan
            if (PrevE == NULL)
            {
                // Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            }
            else
            {
                // Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

// prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X)
{
    // 1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    // 2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    // cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL)
    {
        DisconnectNode(nodeLainnya, nodeHapus); // putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    // 3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    // Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL)
    {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    // 4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus)
    {
        // jika nodeHapus di awal
        G.First = nodeHapus->Next;
    }
    else
    {
        // jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus)
        {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    // 5. delete nodeHapus
    delete nodeHapus;
}

// Menampilkan isi Graph (Adjacency List)
void PrintInfoGraph(Graph G)
{
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL)
    {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL)
        {
            cout << edgeBantu->Node->info << " "; // Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

// Reset status visited sebelum traversal
void ResetVisited(Graph &G)
{
    adrNode nodeReset = G.First;
    while (nodeReset != NULL)
    {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

// traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo)
{
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL)
        return;

    queue<adrNode> Qyu;

    // Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty())
    {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        // Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL)
        {
            if (edgeBantu->Node->visited == 0)
            {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

// Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo)
{
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL)
        return;

    stack<adrNode> Stak;

    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty())
    {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0)
        {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            // masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL)
            {
                if (edgeBantu->Node->visited == 0)
                {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    // Hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ==" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G, 'E') == NULL)
    {
        cout << "Node E berhasil terhapus" << endl;
    }
    else
    {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    return 0;
}
```
Kode di atas menggunakan implementasi ADT untuk membuat suatu Graph. Terdiri dari :
    1. Graph, sebagai komponen utama 
    2. ElmNode, untuk representasikan titik/node
    3. ElmEdge, untuk representasikan garis penghubung antar node.

Fungsi-fungsi yang ada pada program di atas :
    1. CreateGraph()    => inisialisasi graph kosong
    2. AlokasiNode      => mengalokasikan node baru
    3. AlokasiEdge      => mengalokasikan edge baru
    4. InsertNode()     => menambahkan node baru dengan metode insert last
    5. FindNode()       => mencari alamat node berdasarkan informasinya
    6. ConnectNode()    => menghubungkan dua node secara bolak-balik
    7. DisconnectNode() => memutus hubungan antar node
    8. DeleteNode()     => menghapus node beserta semua sisi yang terkait dengannya.
    9. PrintInfoGraph() => menampilkan isi Graph
    10. ResetVisited    => reset status untuk menghindari pengulangan

Program di atas juga mengimplementasikan dua algoritma penelusuran: Breadth First Search (BFS) menggunakan queue, dan Depth     First Search (DFS) menggunakan stack.
    1. BFS mengunjungi simpul secara level-order, dimulai dari simpul awal kemudian semua tetangganya sebelum melanjutkan ke level berikutnya. 
    2. DFS menjelajah graph secara depth-order, mengunjungi satu cabang hingga terdalam sebelum berpindah ke cabang lain.

## Unguided 
### 1. soal unguided 1
Buatlah ADT Graph tidak berarah file “graph.h”:
```
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
    info : infoGraph
    visited : integer
    firstEdge : adrEdge
    Next : adrNode
>
    Type ElmEdge <
    Node : adrNode
    Next : adrEdge
>
    Type Graph <
    first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)
```
Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.
![Gambar 14-14 Ilustrasi Graph](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-13/laprak-modul-14/assets/soal-1.png) </br>

### Jawaban
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next; 
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};
struct Graph{
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);

#endif
```

graph.cpp
```C++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = G.first;
    
    while (P != NULL) {
        if (P->info == X) {
            return;
        }
        P = P->Next;
    }
    
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        newNode->Next = G.first;
        G.first = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2) {
    adrEdge edge1 = new ElmEdge;
    edge1->Node = N2;
    edge1->Next = N1->firstEdge;
    N1->firstEdge = edge1;
    
    adrEdge edge2 = new ElmEdge;
    edge2->Node = N1;
    edge2->Next = N2->firstEdge;
    N2->firstEdge = edge2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "Tidak terhubung";
        } else {
            while (E != NULL) {
                cout << E->Node->info;
                if (E->Next != NULL) {
                    cout << ", ";
                }
                E = E->Next;
            }
        }
        cout << endl;
        P = P->Next;
    }
}
```

main.h
```C++
#include <iostream>
using namespace std;
#include "graph.h"

int main() {
    Graph G; 
    CreateGraph(G);
    
    InsertNode(G, 'H');
    InsertNode(G, 'G');
    InsertNode(G, 'F');
    InsertNode(G, 'E');
    InsertNode(G, 'D');
    InsertNode(G, 'C');
    InsertNode(G, 'B');
    InsertNode(G, 'A');
    
    adrNode nodeA = G.first;
    adrNode nodeB = G.first->Next;
    adrNode nodeC = G.first->Next->Next;
    adrNode nodeD = G.first->Next->Next->Next;
    adrNode nodeE = G.first->Next->Next->Next->Next;
    adrNode nodeF = G.first->Next->Next->Next->Next->Next;
    adrNode nodeG = G.first->Next->Next->Next->Next->Next->Next;
    adrNode nodeH = G.first->Next->Next->Next->Next->Next->Next->Next;

    ConnectNode(nodeA, nodeB);
    ConnectNode(nodeA, nodeC);
    ConnectNode(nodeB, nodeD);
    ConnectNode(nodeB, nodeE);
    ConnectNode(nodeC, nodeF);
    ConnectNode(nodeC, nodeG);
    ConnectNode(nodeD, nodeH);
    ConnectNode(nodeE, nodeH);
    ConnectNode(nodeF, nodeH);
    ConnectNode(nodeG, nodeH);
    
    cout << "=== Graph ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-13/laprak-modul-14/assets/output-1.png)
Program diatas adalah program untuk membuat sebuah Graph dengan mengimlementasikan ADT. Program meminta unutk menghubungkan node A-B-C-D-E-F-G-H seperti pada gambar, dimana dalam struktur terdapat ElmNode untuk merepresentasikan node, dan ElmEdge untuk merepresentasikan edge/garis penghubung antar node.

Fungsi-Fungsi yang ada pada program adalah :
    1. CreateGraph()    => membuat graph kosong
    2. InsertNode()     => menambahkan dan menyisipkan node baru
    3. ConnectNode()    => untuk menghubungkan antar simpul dengan node
    4. PrintInfoGraph() => untuk mencetak/menampilkan graph

### 2. soal unguided 2
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintDFS (Graph G, adrNode N);

### Jawaban
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next; 
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};
struct Graph{
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);

void PrintDFS (Graph G, adrNode N);

#endif
```

graph.cpp
```C++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = G.first;
    
    while (P != NULL) {
        if (P->info == X) {
            return;
        }
        P = P->Next;
    }
    
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        newNode->Next = G.first;
        G.first = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2) {
    adrEdge edge1 = new ElmEdge;
    edge1->Node = N2;
    edge1->Next = N1->firstEdge;
    N1->firstEdge = edge1;
    
    adrEdge edge2 = new ElmEdge;
    edge2->Node = N1;
    edge2->Next = N2->firstEdge;
    N2->firstEdge = edge2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "Tidak terhubung";
        } else {
            while (E != NULL) {
                cout << E->Node->info;
                if (E->Next != NULL) {
                    cout << ", ";
                }
                E = E->Next;
            }
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
        
    stack<adrNode> st;
    st.push(N);
    
    while (!st.empty()) {
        adrNode current = st.top();
        st.pop();
        
        if (current->visited == 0) {
            cout << current->info << " ";
            current->visited = 1;
            
            adrEdge E = current->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    st.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
using namespace std;
#include "graph.h"

int main() {
    Graph G; 
    CreateGraph(G);
    
    InsertNode(G, 'H');
    InsertNode(G, 'G');
    InsertNode(G, 'F');
    InsertNode(G, 'E');
    InsertNode(G, 'D');
    InsertNode(G, 'C');
    InsertNode(G, 'B');
    InsertNode(G, 'A');
    
    adrNode nodeA = G.first;
    adrNode nodeB = G.first->Next;
    adrNode nodeC = G.first->Next->Next;
    adrNode nodeD = G.first->Next->Next->Next;
    adrNode nodeE = G.first->Next->Next->Next->Next;
    adrNode nodeF = G.first->Next->Next->Next->Next->Next;
    adrNode nodeG = G.first->Next->Next->Next->Next->Next->Next;
    adrNode nodeH = G.first->Next->Next->Next->Next->Next->Next->Next;

    ConnectNode(nodeA, nodeB);
    ConnectNode(nodeA, nodeC);
    ConnectNode(nodeB, nodeD);
    ConnectNode(nodeB, nodeE);
    ConnectNode(nodeC, nodeF);
    ConnectNode(nodeC, nodeG);
    ConnectNode(nodeD, nodeH);
    ConnectNode(nodeE, nodeH);
    ConnectNode(nodeF, nodeH);
    ConnectNode(nodeG, nodeH);
    
    cout << "=== Graph ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Print DFS ===" << endl;
    PrintDFS(G, nodeA);
    
    return 0;
}
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-13/laprak-modul-14/assets/output-2.png)
Program diatas adalah program yang melanjutkan unguided 1  untuk membuat sebuah Graph dengan mengimlementasikan ADT. Program meminta unutk menghubungkan node A-B-C-D-E-F-G-H seperti pada gambar, dimana dalam struktur terdapat ElmNode untuk merepresentasikan node, dan ElmEdge untuk merepresentasikan edge/garis penghubung antar node. Di mana program ini menambah sebuah fungsi unutuk mengimplementasikan Depth First Search (DFS)

Fungsi-Fungsi yang ada pada program adalah :
    1. CreateGraph()    => membuat graph kosong
    2. InsertNode()     => menambahkan dan menyisipkan node baru
    3. ConnectNode()    => untuk menghubungkan antar simpul dengan node
    4. PrintInfoGraph() => untuk mencetak/menampilkan graph
Dengan penambahan 
    5. PrintDFS()       => untuk mengimplementasikan dan mengeprint algoritma DFS dari node A

### 3. soal unguided 3
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

### Jawaban
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next; 
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};
struct Graph{
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);

void PrintDFS (Graph G, adrNode N);
void PrintBFS (Graph G, adrNode N);

#endif
```

graph.cpp
```C++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = G.first;
    
    while (P != NULL) {
        if (P->info == X) {
            return;
        }
        P = P->Next;
    }
    
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        newNode->Next = G.first;
        G.first = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2) {
    adrEdge edge1 = new ElmEdge;
    edge1->Node = N2;
    edge1->Next = N1->firstEdge;
    N1->firstEdge = edge1;
    
    adrEdge edge2 = new ElmEdge;
    edge2->Node = N1;
    edge2->Next = N2->firstEdge;
    N2->firstEdge = edge2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "Tidak terhubung";
        } else {
            while (E != NULL) {
                cout << E->Node->info;
                if (E->Next != NULL) {
                    cout << ", ";
                }
                E = E->Next;
            }
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
        
    stack<adrNode> st;
    st.push(N);
    
    while (!st.empty()) {
        adrNode current = st.top();
        st.pop();
        
        if (current->visited == 0) {
            cout << current->info << " ";
            current->visited = 1;
            
            adrEdge E = current->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    st.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}

void PrintBFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
        
    queue<adrNode> q;
    N->visited = 1;
    q.push(N);
    
    while (!q.empty()) {
        adrNode current = q.front();
        q.pop();
        cout << current->info << " ";
        
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
using namespace std;
#include "graph.h"

int main() {
    Graph G; 
    CreateGraph(G);
    
    InsertNode(G, 'H');
    InsertNode(G, 'G');
    InsertNode(G, 'F');
    InsertNode(G, 'E');
    InsertNode(G, 'D');
    InsertNode(G, 'C');
    InsertNode(G, 'B');
    InsertNode(G, 'A');
    
    adrNode nodeA = G.first;
    adrNode nodeB = G.first->Next;
    adrNode nodeC = G.first->Next->Next;
    adrNode nodeD = G.first->Next->Next->Next;
    adrNode nodeE = G.first->Next->Next->Next->Next;
    adrNode nodeF = G.first->Next->Next->Next->Next->Next;
    adrNode nodeG = G.first->Next->Next->Next->Next->Next->Next;
    adrNode nodeH = G.first->Next->Next->Next->Next->Next->Next->Next;

    ConnectNode(nodeA, nodeB);
    ConnectNode(nodeA, nodeC);
    ConnectNode(nodeB, nodeD);
    ConnectNode(nodeB, nodeE);
    ConnectNode(nodeC, nodeF);
    ConnectNode(nodeC, nodeG);
    ConnectNode(nodeD, nodeH);
    ConnectNode(nodeE, nodeH);
    ConnectNode(nodeF, nodeH);
    ConnectNode(nodeG, nodeH);
    
    cout << "=== Graph ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Print DFS ===" << endl;
    PrintDFS(G, nodeA);
    
    cout << "=== Print BFS ===" << endl;
    PrintBFS(G, nodeA);
    return 0;
}
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-13/laprak-modul-14/assets/output-3.png)
Program diatas adalah program yang melanjutkan unguided 1 dan 2 untuk membuat sebuah Graph dengan mengimlementasikan ADT. Program meminta unutk menghubungkan node A-B-C-D-E-F-G-H seperti pada gambar, dimana dalam struktur terdapat ElmNode untuk merepresentasikan node, dan ElmEdge untuk merepresentasikan edge/garis penghubung antar node. Di mana program ini menambah sebuah fungsi untuk mengimplementasikan Breadth First Search (BFS)

Fungsi-Fungsi yang ada pada program adalah :
    1. CreateGraph()    => membuat graph kosong
    2. InsertNode()     => menambahkan dan menyisipkan node baru
    3. ConnectNode()    => untuk menghubungkan antar simpul dengan node
    4. PrintInfoGraph() => untuk mencetak/menampilkan graph
    5. PrintDFS()       => untuk mengimplementasikan dan mengeprint algoritma DFS pada node A
Dengan penambahan 
    6. PrintBFS()       => untuk mengimplementasikan dan mengeprint algoritma BFS pada node A

## Kesimpulan
Graph adalah struktur data non-linear yang terdiri dari himpunan simpul (node atau vertec) dan sisi (edge) yang merepresentasikan relasi. Dalam praktikum ini, Graph diimplementasikan secara dinamis menggunakan Multi Linked List (Multilist) dan pointer. Representasi ini menggunakan struktur ganda (ElmNode untuk simpul dan ElmEdge untuk sisi) yang memungkinkan penambahan dan penghapusan simpul serta sisi yang fleksibel.[1]

Algoritma Penelusuran (Traversal):Dua metode fundamental untuk menelusuri Graph telah berhasil diimplementasikan:
    - Breadth First Search (BFS) diimplementasikan dengan memanfaatkan struktur data Queue (Antrian). BFS menelusuri Graph      secara horizontal (berdasarkan level kedalaman), menjamin bahwa semua simpul di kedalaman telah dikunjungi.
    - Depth First Search (DFS) diimplementasikan dengan memanfaatkan struktur data Stack (Tumpukan). DFS menelusuri Graph secara vertikal (mendalam), mengikuti satu cabang sejauh mungkin sebelum melakukan backtracking untuk menelusuri cabang lainnya.

## Referensi
[1] Ratmaja, M. F. H. (2012). Aplikasi Simulasi Pembelajaran Struktur Data Graph (Doctoral dissertation, Universitas Mercu Buana).<br/>
[2] Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01). yang diakses pada https://jurnal.mifandimandiri.com/index.php/penerbitmmd/article/view/39 <br/>



