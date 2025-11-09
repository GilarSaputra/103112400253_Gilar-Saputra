# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Gilar Saputra - 103112400253</p>

## Dasar Teori
Struktur data Stack (tumpukan) adalah struktur linier yang menggunakan prinsip Last In, First Out (LIFO), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan [1]. Implementasi stack dapat dilakukan dengan menggunakan array (statis) ataupun linked list (dinamis) [2]. Dalam implementasi array biasanya terdapat variabel indeks “top” yang menunjukkan posisi elemen teratas dan menjadi acuan utama dalam setiap operasi push maupun pop.

Operasi dasar pada stack antara lain [1]:
    1. Push – menambahkan elemen ke posisi top.
    2. Pop – menghapus (dan mengembalikan) elemen pada posisi top.
    3. Peek / top (opsional) – melihat elemen teratas tanpa menghapus.

Penggunaan stack sangat luas, misalnya pada sistem undo-redo, pemrosesan ekspresi matematika, backtracking, parsing, dan berbagai aplikasi lainnya [2]. Dalam pembelajaran struktur data, stack juga digunakan sebagai dasar untuk memahami konsep kontrol alur, antrian fungsi (function call), serta penyimpanan data sementara dalam algoritma [1].

Dalam pengembangan lebih lanjut, konsep seperti pushAscending (penyisipan data agar urut menaik/ascending) atau balikStack (reverse stack) menunjukkan bahwa struktur stack dapat dimodifikasi untuk memenuhi kebutuhan pengurutan (sorting) atau manipulasi urutan data [3]. Contohnya pada penelitian [3] yang menerapkan stack dan array dalam pengurutan data lagu menggunakan metode selection sort, di mana prinsip urutan menaik (ascending) digunakan untuk menghasilkan data yang terurut dari bawah ke atas.

Dalam praktik implementasi menggunakan array, kapasitas (misalnya 20 elemen) dibatasi, variabel top diinisialisasi ke –1 untuk menunjukkan kondisi kosong, kemudian setiap operasi push atau pop memperbarui indeks top dan isi array. Fungsi tambahan seperti pembalikan urutan (reverse) atau penyisipan menaik (ascending) dapat dilakukan dengan memanfaatkan stack bantu atau algoritma internal [2].

Dengan demikian, pemahaman dasar tentang prinsip kerja stack (LIFO), keterbatasan implementasi (overflow, underflow), serta penambahan fitur manipulasi urutan menjadi landasan teori penting bagi praktikum implementasi stack seperti yang dilakukan pada percobaan ini [1].

### A. Materi Praktikum <br/>
...
#### 1. Stack
#### 2. Push - untuk memasukan nilai ke dalam stack
#### 2. Pop -  untuk mengambil nilai dari stack

### B. Tugas Laprak <br/>
...
#### 1. Soal Unguided 1
#### 2. Soal Unguided 2
#### 3. Soal Unguided 3


## Guided 

### 1. Guided 1
stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack)
{
    if (listStack.top == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack &listStack)
{
    listStack.top = Nil;
}

address alokasi(int angka)
{
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru)
{
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack)
{
    address nodeHapus;
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi)
{
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        if (posisi == 0)
        {
            cout << "Posisi tidak valid!" << endl;
        }
        else
        {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while (nodeBantu != Nil)
            {
                if (count < posisi)
                {
                    nodeBantu = nodeBantu->next;
                    count++;
                }
                else if (count == posisi)
                {
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while (nodeBantu != Nil)
        {
            if (nodeBantu->dataAngka == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            }
            else
            {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if (found == false)
        {
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini mengimplementasikan struktur data Stack (tumpukan) menggunakan Linked List. Stack bersifat LIFO (Last In, First Out), artinya elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan.
Operasi utama yang dilakukan adalah:
    1. push() = menambah elemen ke atas stack
    2. pop() = menghapus elemen teratas
    3. update() = memperbarui nilai data pada posisi tertentu
    4. view() = menampilkan seluruh isi stack
    5. searchData() = mencari elemen berdasarkan nilai data

### 2. Guided 2
stack.h
```C++

#ifndef STACK_TABLE
#define STACK_TABLE
#include <iostream>
using namespace std;
// Ubah kapasitas sesuai kebutuhan const int MAX = 10;
const int MAX = 10;

struct stackTable
{
    int data[MAX];
    int top; //-1 = kosong
};
bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);
void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);
#endif
```

stack.cpp
```C++

#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s)
{
    return s.top == -1;
}
bool isFull(stackTable s)
{
    return s.top == MAX - 1;
}
void createStack(stackTable &s)
{
    s.top = -1;
}
void push(stackTable &s, int angka)
{

    if (isFull(s))
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data" << angka << "berhasil ditambahkan kedalam stack !" << endl;
    }
}

void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout << "Data" << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi)
{
    if (isEmpty(s))
    {
    }
    cout << "Stack kosong!" << endl;
    return;
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Program ini merupakan implementasi struktur data Stack menggunakan array statis.Fungsi utama dari program ini adalah untuk menyimpan, menghapus, memperbarui, dan mencari data dalam urutan tertentu — sesuai prinsip LIFO (Last In, First Out), yaitu data yang terakhir masuk akan menjadi yang pertama keluar.
Stack disimpan dalam bentuk array berukuran tetap (MAX = 10).
    Saat top = -1, artinya stack masih kosong.
    Setiap kali data ditambahkan (push), top naik satu tingkat.
    Saat data dihapus (pop), top turun satu tingkat.
Operasi utama pada stack ini adalah:
    1. Push → menambah data ke puncak (top) stack
    2. Pop → menghapus data dari puncak stack
    3. Update → memperbarui nilai data pada posisi tertentu
    4. View → menampilkan seluruh isi stack
    5. SearchData → mencari posisi data tertentu

## Unguided 
### 1. soal unguided 1
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
```
Type infotype : integer
Type Stack <
    info : array [20] of integer
    top : integer
>
procedure CreateStack( input/output S : Stack )
procedure push(input/output S : Stack, input x : infotype)
function pop(input/output t S : Stack ) → infotype
procedure printInfo( input S : Stack ) 
procedure balikStack(input/output S : Stack )
```
Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”
```
int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
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
struct Stack {
    int info[20];
    int top;
};

// Soal 1
void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

stack.cpp
```C++
#include "stack.h"

void CreateStack(Stack &S){
    S.top = -1;
}

void Push(Stack &S, infotype x){
    S.top++;
    S.info[S.top] = x;
}

infotype Pop(Stack &S){
    if (S.top > -1) {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    } else {
        cout << "Stack Kosong";
        return -1;
    }
}


void printInfo(Stack S){
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i){
        cout << S.info[i] << " ";
    };
    cout << endl;
}

void balikStack(Stack &S){
    Stack temp;
    CreateStack(temp);
    while (S.top >= 0) {
        Push(temp, Pop(S));
    }
    S = temp;
}
```

main.h
```C++
#include "stack.h"

int main(){
    cout << "Hello world!" << endl;
    Stack S;    
    CreateStack(S);

    Push(S,3);
    Push(S,4);
    Push(S,8);
    Pop(S);
    Push(S,2);
    Push(S,3);
    Pop(S);
    Push(S,9);
    printInfo(S);

    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-7/Laprak-modul-7/assets/output-1.png)<br/>
Program ini mengimplementasikan Abstract Data Type (ADT) Stack menggunakan array statis berkapasitas 20 elemen (int info[20]). Stack bersifat LIFO (Last In, First Out) — elemen terakhir yang dimasukkan akan menjadi elemen pertama yang diambil. 
Program terdiri dari tiga bagian utama: definisi tipe (stack.h), implementasi operasi stack (stack.cpp), dan program utama (main).

Program ini mengimplementasikan stack menggunakan array dengan operasi dasar CreateStack, Push, Pop, printInfo, dan balikStack. top menyimpan indeks puncak; Push menambah elemen di posisi top+1; Pop menghapus dan mengembalikan nilai puncak; balikStack membalik urutan elemen menggunakan stack bantu. Operasi Push/Pop bersifat O(1), sedangkan operasi cetak dan pembalikan bersifat O(n).

### 2. soal unguided 2
Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
```
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
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
struct Stack {
    int info[20];
    int top;
};

// Soal 1
void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Soal 2
void pushAscending(Stack &S, int x);

#endif
```

stack.cpp
```C++
#include "stack.h"

void CreateStack(Stack &S){
    S.top = -1;
}

void Push(Stack &S, infotype x){
    S.top++;
    S.info[S.top] = x;
}

infotype Pop(Stack &S){
    if (S.top > -1) {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    } else {
        cout << "Stack Kosong";
        return -1;
    }
}


void printInfo(Stack S){
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i){
        cout << S.info[i] << " ";
    };
    cout << endl;
}

void balikStack(Stack &S){
    Stack temp;
    CreateStack(temp);
    while (S.top >= 0) {
        Push(temp, Pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, int x){
    Stack simpan;
    CreateStack(simpan);

    while (S.top >= 0 && S.info[S.top] > x){
        Push(simpan, Pop(S));
    }
    Push(S, x);
    
    while (simpan.top >= 0){
        Push(S, Pop(simpan));
    }

}
```

main.cpp
```C++
#include "stack.h"

int main(){
    cout << "Hello world!" << endl;
    Stack S;

    CreateStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);

    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
```
### Output Unguided 2:
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-7/Laprak-modul-7/assets/output-2.png)<br/>
Melanjutkan kode pada Unguided 1,
Program ini bertujuan untuk mengimplementasikan struktur data Stack berbasis array statis, dengan tambahan fitur:
    1. Operasi dasar (Push, Pop, printInfo, balikStack) menunjukkan prinsip LIFO.
    2. Push Ascending: memasukkan elemen ke dalam stack agar tetap dalam urutan menaik (ascending), dan
    3. Balik Stack: membalik urutan seluruh elemen stack
Pada kode ini, penambahan utama adalah fitur pushAscending dimana urutan elemen mulai dari kecil ke besar, lalu di balik.

### 3. soal unguided 3
Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
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
struct Stack {
    int info[20];
    int top;
};

// Soal 1
void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Soal 2
void pushAscending(Stack &S, int x);

// Soal 3
void getInputStream(Stack &S);

#endif
```

stack.cpp
```C++
#include "stack.h"

void CreateStack(Stack &S){
    S.top = -1;
}

void Push(Stack &S, infotype x){
    S.top++;
    S.info[S.top] = x;
}

infotype Pop(Stack &S){
    if (S.top > -1) {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    } else {
        cout << "Stack Kosong";
        return -1;
    }
}


void printInfo(Stack S){
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i){
        cout << S.info[i] << " ";
    };
    cout << endl;
}

void balikStack(Stack &S){
    Stack temp;
    CreateStack(temp);
    while (S.top >= 0) {
        Push(temp, Pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, int x){
    Stack simpan;
    CreateStack(simpan);

    while (S.top >= 0 && S.info[S.top] > x){
        Push(simpan, Pop(S));
    }
    Push(S, x);
    
    while (simpan.top >= 0){
        Push(S, Pop(simpan));
    }
}

void getInputStream(Stack &S){
    char input;
    
    while (true) {
        input = cin.get();
        if (input == '\n')
            break;
        if (isdigit(input)) { 
            int angka = input - '0';
            Push(S, angka);
        }
    }
}
```

main.cpp
```C++
#include "stack.h"

int main(){
    cout << "Hello world!" << endl;
    Stack S;

    CreateStack(S);
    getInputStream(S);
    printInfo(S);

    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
```
### Output Unguided 3:
![Screenshot Output Unguided 3](https://raw.githubusercontent.com/GilarSaputra/103112400253_Gilar-Saputra/main/Pertemuan-7/Laprak-modul-7/assets/output-3.png)<br/>
Melanjutkan kode unguided 1 dan 2
Program ini adalah implementasi struktur data Stack berbasis array statis dengan kapasitas maksimum 20 elemen.
Stack bekerja dengan prinsip LIFO (Last In, First Out), yaitu data terakhir yang dimasukkan akan menjadi data pertama yang dikeluarkan.

Selain operasi dasar seperti push, pop, dan print, program ini juga memiliki fitur tambahan:
    - Membalik urutan stack (balikStack)
    - Menjaga urutan menaik saat push (pushAscending)
    - Membaca input langsung dari keyboard (getInputStream)

## Kesimpulan
Berdasarkan hasil praktikum implementasi struktur data stack menggunakan bahasa C++, dapat disimpulkan bahwa struktur data stack berhasil diimplementasikan sesuai prinsip Last In, First Out (LIFO), di mana elemen terakhir yang dimasukkan menjadi elemen pertama yang dikeluarkan [1]. Melalui proses inisialisasi, penambahan (push), dan penghapusan (pop), program mampu mengelola data secara efisien menggunakan array statis dan variabel pengendali top untuk menentukan posisi elemen teratas [2].

Selain operasi dasar, fungsi tambahan seperti balikStack dan pushAscending menunjukkan bahwa stack dapat dimodifikasi untuk melakukan manipulasi urutan data. Fitur pushAscending memungkinkan penyisipan elemen dengan mempertahankan urutan menaik, sedangkan balikStack membalik seluruh isi stack menggunakan stack bantu, sehingga memperluas pemahaman mengenai aplikasi algoritmik pada struktur data linear [3].

Secara keseluruhan, praktikum ini memperkuat pemahaman mengenai konsep dasar stack, penerapannya dalam pemrograman, serta bagaimana struktur data ini dapat dikembangkan untuk mendukung kebutuhan kompleks seperti pengurutan, pembalikan data, dan pemrosesan input secara dinamis. Konsep ini sejalan dengan penelitian-penelitian sebelumnya yang menekankan pentingnya penerapan stack baik dalam proses pembelajaran maupun dalam implementasi algoritma manipulasi data [1][2][3].

## Referensi
[1] Arif Aliyanto, “Sistem Pembelajaran Algoritma Stack dan Queue dengan Pendekatan Problem Based Learning Untuk Mendukung Pembelajaran Struktur Data”, Jurnal SNATI, Universitas Islam Indonesia, 2010. Available: https://journal.uii.ac.id/Snati/article/download/2208/2031/2227 <br/>
[2] Risky Dwi Setiyawan, dkk., “Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List”, Jurnal Teknologi Komputer (JUTECH), STKIP Persada Khatulistiwa, 2023. Available: https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf <br/>
[3] Ghina Mawarni Putri, dkk., “Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort”, Jurnal Teknologi dan Sistem Informasi (JTEKSIS), Universitas Dharma Andalas, 2022. Available: https://jurnal.unidha.ac.id/index.php/jteksis/article/view/1192<br/>


