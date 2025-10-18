#include "Singlylist.h"

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address p = new Elmlist;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = nullptr;
}

void printInfo(List L) {
    address p = L.First;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(List &L, address p) {
    p->next = L.First;
    L.First = p;
}
