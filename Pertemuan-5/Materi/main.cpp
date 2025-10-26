#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    CreateList(L);

    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);     
    insertLast(L, nodeA);       
    insertAfter(L, nodeD, nodeB); 
    insertFirst(L, nodeC);
    insertLast (L, nodeE);
    insertFirst (L, nodeF);
    delAfter (L, nodeB, nodeC);

    // Soal Nomor 1
    cout << "List sebelum update:" << endl;
    printList(L);              

    updateFirst(L);          
    updateAfter(L, nodeD);   
    updateLast(L);       
    updateAfter(L, nodeF);  

    cout << endl << "List setelah update:" << endl;
    printList(L);     
    
    SearchByData(L, 20);   
    SearchByData(L, 55);  
    SearchByAddress(L, nodeB); 
    SearchByAddress(L, nodeA); 
    SearchByRange(L, 40); 

    cout << endl;
    cout << "===============================" << endl;
    cout << "   Operasi Aritmetika List" << endl;
    cout << "===============================" << endl;

    sumList(L);
    subList(L);
    multiplyList(L);


    return 0;
};
