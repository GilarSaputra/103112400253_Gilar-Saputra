# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Struktur data **queue** merupakan salah satu bentuk struktur data linier yang dirancang untuk mengatur proses penyimpanan dan pengambilan data dengan menggunakan prinsip **FIFO (First In First Out)**. Pada prinsip ini, elemen yang pertama masuk menjadi elemen yang pertama keluar. Berbagai penelitian menjelaskan bahwa mekanisme antrian ini berfungsi menjaga alur pemrosesan data tetap teratur sehingga tidak terjadi lompatan atau perubahan urutan secara tidak terkontrol [1]. Sifat FIFO tersebut menjadikan queue sebagai struktur penting pada algoritma atau sistem yang membutuhkan eksekusi berurutan dan konsisten.

Queue memiliki dua operasi utama, yaitu **enqueue** dan **dequeue**. Operasi *enqueue* digunakan untuk menambah elemen baru di bagian belakang antrian (*tail*), sedangkan operasi *dequeue* berfungsi menghapus elemen dari bagian depan antrian (*head*). Literatur yang membahas implementasi struktur data linier menjelaskan bahwa kedua operasi ini merupakan inti dari mekanisme antrian dan memerlukan pengelolaan pointer yang tepat, baik dalam representasi berbasis array maupun linked list [2]. Pada implementasi menggunakan linked list, pointer *head* bertugas menunjuk elemen pertama, sementara pointer *tail* menunjuk elemen terakhir sehingga penambahan elemen tidak memerlukan proses pergeseran data, yang membuat operasinya lebih fleksibel.

Selain representasi menggunakan linked list, queue juga dapat diterapkan menggunakan **array** dengan beberapa variasi model pengelolaan indeks, seperti *static queue*, *dynamic queue*, dan **circular queue**. Circular queue, sebagaimana banyak dibahas dalam penelitian mengenai efisiensi struktur data array, memberikan kemampuan untuk memanfaatkan ruang secara optimal melalui mekanisme indeks melingkar (*modular arithmetic*), sehingga *head* dan *tail* dapat bergerak ke awal array tanpa membutuhkan pergeseran elemen [3]. Teknik ini sekaligus mengatasi masalah *false full*, yaitu kondisi ketika array terlihat penuh padahal masih memiliki ruang yang tidak dapat digunakan.

Dalam konteks pemrosesan komputer, queue juga memiliki peran penting sebagai mekanisme pengatur aliran data yang stabil dan berurutan. Penelitian mengenai manajemen proses dan penjadwalan menunjukkan bahwa queue mampu menjaga efisiensi pemrosesan dengan memastikan setiap elemen dieksekusi sesuai urutan kedatangannya [4]. Untuk mendukung fungsinya, queue dilengkapi dengan serangkaian operasi pendukung seperti *isEmpty*, *isFull*, *createQueue*, hingga *destroyQueue*, yang memastikan struktur antrian dapat beroperasi dengan stabil. Melalui pengelolaan yang tepat, queue dapat digunakan secara optimal baik dalam simulasi, algoritma, maupun sistem yang membutuhkan model pemrosesan berurutan.

### A. Materi Praktikum <br/>
...
#### 1.Create Queue - untuk membuat sebuah queue
#### 2.EnQueueu - unutuk memasukan nilai ke dalam antrian (queue) 
#### 3.DeQueue - untuk menghapus nilai dari dalam antrian (dari head)
#### 4.3 cara dalam implementasi Queue

### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Guided 1
stack.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

typedef struct node *address;

struct Node{
    string nama;
    Node* next;
};

struct queue{
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q); 

#endif
```

stack.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue Q) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Program ini mengimplementasikan  struktur data Queue dinamis. Struktur data ini terdiri dari dua komponen utama: `struct Node` dan `struct queue`. `Node` berfungsi sebagai elemen penyimpan data, yang dalam program ini adalah `string nama`, serta sebuah pointer `next` yang menunjuk ke elemen berikutnya. `struct queue` bertindak sebagai pengelola antrian dengan menyimpan dua pointer: `head` (penunjuk elemen terdepan) dan `tail` (penunjuk elemen terakhir). Implementasi ini menerapkan prinsip **FIFO (First-In, First-Out)**, di mana data yang pertama masuk adalah data yang pertama keluar.

Cara kerja program diatur oleh beberapa fungsi utama. Fungsi `CreateQueue` digunakan untuk inisialisasi antrian baru dengan mengatur `head` dan `tail` menjadi `nullptr`. Operasi penambahan data dilakukan oleh fungsi `enQueue`, yang membuat `Node` baru dan menempatkannya di akhir antrian (ditunjuk oleh `tail`), lalu memperbarui `tail` ke node baru tersebut. Operasi penghapusan data dilakukan oleh fungsi `deQueue`, yang menghapus `Node` dari depan antrian (ditunjuk oleh `head`), membebaskan memorinya, dan memperbarui `head` ke `Node` berikutnya. Program juga dilengkapi fungsi-fungsi pendukung seperti `isEmpty` untuk memeriksa apakah antrian kosong, `isFull` (yang selalu mengembalikan `false` karena *linked list* bersifat dinamis), `viewQueue` untuk mencetak seluruh isi antrian dari `head` ke `tail`, dan `clearQueue` untuk mengosongkan seluruh antrian. Fungsi `main()` bertindak sebagai *driver* untuk menguji fungsionalitas antrian dengan menambahkan enam nama, menampilkan isinya, menghapus empat nama terdepan, dan menampilkan sisa antrian sebelum akhirnya membersihkannya.

### 2. Guided 2
stack.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];   
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q); 

#endif
```

stack.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini merupakan implementasi dari struktur data Queue (Antrian) yang menggunakan array statis. Struktur ini didefinisikan dalam `struct queue` yang berisi sebuah array `string nama` dengan kapasitas tetap `MAKSIMAL` (bernilai 5), serta dua penanda indeks berupa integer, `head` (kepala) dan `tail` (ekor). Prinsip kerja yang diterapkan adalah **FIFO (First-In, First-Out)**, di mana data yang pertama masuk adalah data yang pertama keluar. menggunakan 3 alternatif cara 

Implementasi 1: Head Diam, Tail Bergerak
Program ini merupakan implementasi dari struktur data Queue (Antrian) yang menggunakan array statis dengan kapasitas MAKSIMAL 5. Struktur ini menggunakan prinsip FIFO, yang berarti First-In, First-Out, dengan dua penanda indeks, head dan tail.  Dalam penggunaan ini, kepala, atau kepala, tetap statis dan selalu menunjuk ke indeks 0 (kecuali dalam antrian kosong di mana kepala dan ekor bernilai -1).  Operasi enQueue dilakukan dengan menaikkan ekor dan memasukkan data ke indeks ekor.  Operasi deQueue adalah karakteristik utama dari pendekatan ini. Setelah data pada Q.nama[head] (indeks 0) dihapus, seluruh elemen antrian yang tersisa digeser (dipindahkan) satu posisi ke depan untuk mengisi kekosongan tersebut.

Implementasi 2: Head dan Tail Bergerak
Program ini mengimplementasikan Queue (Antrian) menggunakan array statis berkapasitas MAKSIMAL 5, dengan menerapkan prinsip FIFO (First-In, First-Out). Implementasi ini menggunakan dua penanda indeks, head (kepala) dan tail (ekor), yang keduanya dapat bergerak. Saat inisialisasi, head dan tail diatur ke -1. Operasi enQueue menambahkan data dengan meng-increment tail dan menempatkan data pada Q.nama[tail]. Berbeda dari metode pertama, operasi deQueue di sini jauh lebih efisien (O(1)); penghapusan data dilakukan secara logis hanya dengan meng-increment indeks head (head++). Tidak ada pergeseran data fisik yang terjadi. 

Implementasi 3: Head dan Tail Berputar
Program ini mengimplementasikan Queue (Antrian) menggunakan array statis berkapasitas MAKSIMAL 5. Struktur ini menggunakan indeks head dan tail yang bergerak secara "berputar" mengelilingi array menggunakan aritmatika modular. Operasi enQueue memperbarui tail dengan rumus Q.tail = (Q.tail + 1) % MAKSIMAL sebelum menyisipkan data. Demikian pula, operasi deQueue memperbarui head dengan rumus Q.head = (Q.head + 1) % MAKSIMAL untuk menghapus data. Mekanisme ini memungkinkan tail untuk "melompat" kembali ke indeks 0 jika head sudah bergeser, sehingga ruang kosong yang ditinggalkan oleh deQueue dapat segera digunakan kembali. Pengecekan isFull disesuaikan menjadi (Q.tail + 1) % MAKSIMAL == Q.head, yang secara efektif memanfaatkan seluruh kapasitas array secara optimal.

## Unguided 
### 1. soal unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
```
Type infotype: integer
Type Queue: <
    info : array [5] of infotype {index array dalam C++
    dimulai dari 0}
    head, tail : integer
>
procedure CreateQueue (input/output Q: Queue)
function isEmptyQueue (Q: Queue) → boolean
function isFullQueue (Q: Queue) → boolean
procedure enqueue (input/output Q: Queue, input x: infotype)
function dequeue (input/output Q: Queue) → infotype
procedure printInfo (input Q: Queue)
```
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
```
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Jawaban
stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;
struct Queue {
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmpetyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue &Q);

#endif
```

stack.cpp
```C++
#include "queue.h"

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpetyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }    
}

bool isFullQueue(Queue Q){
    if(Q.tail == 4){
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue full!" << endl;
    } else {
        if(isEmpetyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if(isEmpetyQueue(Q)){
        cout << "Queue Kosong" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    } else {
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;      
        Q.head = 0;
    }

    return temp;
}

void printInfo(Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t | ";

    if(isEmpetyQueue(Q)){
        cout << "Queue Kosong" << endl;
        return;
    }

    for(int i = Q.head; i <= Q.tail; i++){
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

main.h
```C++
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------" << endl;
    cout << "H - T\t | Queue info" << endl;
    cout << "-----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-8/Laprak-modul-8/assets/output-1.png)<br/>
Program ini berfungsi untuk mengimplementasikan struktur data Queue (Antrian) menggunakan array statis berkapasitas 5 elemen  mengikuti prinsip FIFO (First-In, First-Out).Menggunakan alternatif 1 (Head diam, tail bergerak).

1. CreateQueue => membuat antrian queue dan Mengatur head dan tail menjadi -1.
2. isEmpetyQueue => mengecek queue kosong ata tidak, Mengembalikan true jika head dan tail adalah -1.
3. isFullQueue => mengecek queue penuh ata tidak, Mengembalikan true jika tail mencapai indeks maksimum 4.
4. enqueue => menambah Data (FIFO),Menempatkan elemen baru di posisi tail dan meng-increment tail.
5. dequeue => menghapus Data (FIFO),"Mengambil elemen di head (indeks 0), menggeser semua elemen sisa ke depan, dan mendekrementasi tail."
6. printInfo => Menampilkan hasil queue "Mencetak nilai head, tail, dan seluruh isi antrian dari Q.head hingga Q.tail."

### 2. soal unguided 2
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

### Jawaban
stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;
struct Queue {
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmpetyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue &Q);

#endif
```

stack.cpp
```C++
#include "queue.h"

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpetyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }    
}

bool isFullQueue(Queue Q){
    if(Q.tail == 4){
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue full!" << endl;
    } else {
        if(isEmpetyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if(isEmpetyQueue(Q)){
        cout << "Queue Kosong" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    return temp;
}

void printInfo(Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t | ";

    if(isEmpetyQueue(Q)){
        cout << "Queue Kosong" << endl;
        return;
    }

    for(int i = Q.head; i <= Q.tail; i++){
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------" << endl;
    cout << "H - T\t | Queue info" << endl;
    cout << "-----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-8/Laprak-modul-8/assets/output-2.png)<br/>
Program ini berfungsi untuk  mengimplementasikan Queue menggunakan array statis di mana head dan tail keduanya bergerak maju. Elemen baru ditambahkan dengan memajukan tail. Saat elemen dihapus oleh dequeue, elemen tidak digeser, melainkan head yang dimajukan (Q.head++) secara logis menghapus elemen tersebut. Menggunakan alternaif 2 (Head, dan tail bergerak).

1. CreateQueue => membuat antrian queue dan Mengatur head dan tail menjadi -1.
2. isEmpetyQueue => mengecek queue kosong ata tidak, Mengembalikan true jika head dan tail adalah -1.
3. isFullQueue => mengecek queue penuh ata tidak, Mengembalikan true jika tail mencapai indeks maksimum 4.
4. enqueue => menambah Data (FIFO),Menempatkan elemen baru di posisi tail dan meng-increment tail.
5. dequeue => menghapus Data (FIFO),Mengambil elemen di head, dan meng-increment head (Q.head++). Tidak ada pergeseran data.
6. printInfo => Menampilkan hasil queue "Mencetak nilai head, tail, dan seluruh isi antrian dari Q.head hingga Q.tail."

### 3. soal unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

### Jawaban
stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;
struct Queue {
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmpetyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue &Q);

#endif
```

stack.cpp
```C++
#include "queue.h"

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpetyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }    
}

bool isFullQueue(Queue Q){
    if((Q.tail + 1) % 5 == Q.head ){
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }

    if(isEmpetyQueue(Q)){
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmpetyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    if(Q.head == Q.tail){
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;
    }

    return temp;

    return temp;
}

void printInfo(Queue &Q){
    if(isEmpetyQueue(Q)){
        cout << Q.head << " - " << Q.tail << " | Queue Kosong" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " \t| ";

    int i = Q.head;
    while (true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;

        i = (i + 1) % 5;
    }

    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------" << endl;
    cout << "H - T\t | Queue info" << endl;
    cout << "-----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-8/Laprak-modul-8/assets/output-3.png)<br/>
Program ini berfungsi untuk mengimplementasikan struktur data Circular Queue (Antrian Melingkar) menggunakan array statis berkapasitas 5 elemen. Program ini secara efisien mematuhi prinsip FIFO (First-In, First-Out) dan mengatasi masalah "False Full" pada Linear Queue dengan memungkinkan indeks head dan tail berputar kembali ke awal array menggunakan aritmatika modular (operasi % 5).

1. CreateQueue => membuat antrian queue dan Mengatur head dan tail menjadi -1.
2. isEmpetyQueue => mengecek queue kosong ata tidak, Mengembalikan true jika head dan tail adalah -1.
3. isFullQueue => mengecek queue penuh ata tidak, Mengembalikan true jika (Q.tail + 1) % 5 == Q.head. Ini menggunakan satu slot kosong untuk membedakan antara kondisi penuh dan kosong.
4. enqueue => menambah Data (FIFO),Memperbarui tail menggunakan aritmatika modular ((Q.tail + 1) % 5), memungkinkan tail berputar kembali ke indeks 0.
5. dequeue => Data (FIFO)	Mengambil elemen di head, lalu memperbarui head menggunakan aritmatika modular ((Q.head + 1) % 5), yang memungkinkan head berputar.
6. printInfo => Mencetak head, tail, dan seluruh isi antrian dengan melakukan perulangan secara melingkar dari head hingga tail.

## Kesimpulan
Praktikum Modul 8 membuktikan bahwa struktur data queue yang menerapkan prinsip FIFO (First In First Out) dapat diimplementasikan secara konsisten melalui dua pendekatan utama, yaitu menggunakan linked list dan array statis. Seluruh operasi fundamental—enqueue, dequeue, dan viewQueue—berjalan sesuai dengan konsep teoritis yang dijelaskan dalam literatur ilmiah, di mana struktur antrian berfungsi mempertahankan urutan data agar tetap stabil dan teratur selama proses pemrosesan berlangsung [1].

Implementasi queue berbasis linked list menunjukkan fleksibilitas memori dan efisiensi yang lebih tinggi karena operasi penambahan maupun penghapusan elemen tidak membutuhkan pergeseran data. Temuan ini selaras dengan pembahasan dalam jurnal mengenai efektivitas struktur data dinamis dalam meminimalkan operasi berbiaya tinggi seperti shifting [2]. Sebaliknya, implementasi queue berbasis array statis menampilkan perbedaan karakteristik antara tiga model operasional: alternatif 1 (head diam), alternatif 2 (head bergerak), dan circular queue. Hasil praktikum memperlihatkan bahwa alternatif 1 kurang efisien akibat pergeseran elemen, sedangkan alternatif 2 lebih efisien karena penghapusan hanya dilakukan melalui pergeseran indeks. Circular queue menjadi model paling optimal dengan penggunaan ruang yang lebih maksimal melalui mekanisme indeks melingkar, sebagaimana dibahas dalam penelitian mengenai pemanfaatan array secara efektif [3].

Secara keseluruhan, hasil praktikum mendukung temuan akademik bahwa queue merupakan struktur penting dalam pengelolaan aliran data yang memerlukan pemrosesan berurutan dan konsisten, terutama pada sistem komputasi yang menuntut keteraturan proses [4]. Praktikum memberikan gambaran konkret tentang bagaimana teori queue diimplementasikan dalam kode program dan bagaimana variasi representasi dapat memengaruhi performa, efisiensi, dan penggunaan memori. Dengan demikian, pemahaman teoritis dari jurnal-jurnal terkait dapat dipadukan secara utuh dengan hasil implementasi praktikum.

## Referensi
[1]Sahid, S., Pasaribu, F. S., Simanullang, M. M. F., & Lubis, M. R. (2025). Implementasi Queue Berbasis Linked List Pada Aplikasi Web Manajemen Antrian Print Mahasiswa. Jurnal Ilmu Komputer dan Informatika (JIKI). Available: https://jurnal.globalscients.com/index.php/jiki/article/view/709<br/>
[2]Christian, E., Kristianti, N., Anugrahnu, D. P., Putra, P. B. A., & Pranatawijaya, V. H. (2025). Implementasi Algoritma FIFO dan Descending Priority Queue pada Sistem Antrian Pelayanan Kesehatan Puskesmas Buntok. Jurnal Teknologi Informasi (JTI). Available: https://e-journal.upr.ac.id/index.php/JTI/article/view/19246<br/>
[3]Elisama, Y., Warisaji, T. T., & Cahyanto, T. A. (2025). Analisis Kinerja Quality Of Service Menggunakan Metode Queue Tree dan Simple Queue. JUSTINDO (Jurnal Sistem dan Teknologi Informasi Indonesia). Available: https://ejurnal.unmuhjember.ac.id/index.php/JUSTINDO/article/view/3264<br/>
[4]Firmansyah, A., Ijudin, A., Seha, N., Rahmawati, R. N., Rustamaji, R., Peritami, S. A., & Thoyyibah, T. (2024). Analisis Kinerja Metode Simple Queue untuk Meningkatkan Kualitas Jaringan Manajemen Bandwith. Digital Transformation Technology. Available: https://jurnal.itscience.org/index.php/digitech/article/view/3980<br/>


