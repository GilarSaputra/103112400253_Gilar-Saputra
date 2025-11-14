// Harap perhatikan bagian isFullQueue,enqueue,dequeue dan printInfo

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

// Opsi fitur isFullQueue START *pilih salah 1 
// // == UNUTK SOAL NOMOR 1 DAN 2 ==
// bool isFullQueue(Queue Q){
//     if(Q.tail == 4){
//         return true;
//     } else {
//         return false;
//     }
// }

// // == UNUTK SOAL NOMOR 3 ==
bool isFullQueue(Queue Q){
    if((Q.tail + 1) % 5 == Q.head ){
        return true;
    } else {
        return false;
    }
}
// Opsi fitur isFullQueue END


// Opsi fitur equeue START *pilih salah 1 
// // === UNTUK SOAL 1 & 2 ===
// void enqueue(Queue &Q, infotype x){
//     if(isFullQueue(Q)){
//         cout << "Queue full!" << endl;
//     } else {
//         if(isEmpetyQueue(Q)){
//             Q.head = 0;
//             Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.info[Q.tail] = x;
//     }
// }

// // === UNTUK SOAL 3 ===
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
// Opsi fitur equeue END


// Opsi fitur dequeue START *pilih salah 1 
// //  === UNTUK SOAL NOMOR 1 ===
// infotype dequeue(Queue &Q){
//     if(isEmpetyQueue(Q)){
//         cout << "Queue Kosong" << endl;
//         return -1;
//     }

//     infotype temp = Q.info[Q.head];

//     if(Q.head == Q.tail){
//         Q.head = -1;
//         Q.tail = -1;
//     } else {
//         for(int i = Q.head; i < Q.tail; i++){
//             Q.info[i] = Q.info[i + 1];
//         }
//         Q.tail--;      
//         Q.head = 0;
//     }

//     return temp;
// }

// //  === UNTUK SOAL NOMOR 2 ===
// infotype dequeue(Queue &Q){
//     if(isEmpetyQueue(Q)){
//         cout << "Queue Kosong" << endl;
//         return -1;
//     }

//     infotype temp = Q.info[Q.head];

//     if(Q.head == Q.tail){
//         Q.head = -1;
//         Q.tail = -1;
//     } else {
//         Q.head++;
//     }

//     return temp;
// }

//  === UNTUK SOAL NOMOR 3 ===
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
// Opsi fitur dequeue END

// Opsi fitur printInfo START *pilih salah 1 
// //  === UNTUK SOAL NOMOR 1&2 ===
// void printInfo(Queue &Q){
//     cout << Q.head << " - " << Q.tail << "\t | ";

//     if(isEmpetyQueue(Q)){
//         cout << "Queue Kosong" << endl;
//         return;
//     }

//     for(int i = Q.head; i <= Q.tail; i++){
//         cout << Q.info[i] << " ";
//     }
//     cout << endl;
// }

// //  === UNTUK SOAL NOMOR 3 ===
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
// Opsi fitur printInfo END 
