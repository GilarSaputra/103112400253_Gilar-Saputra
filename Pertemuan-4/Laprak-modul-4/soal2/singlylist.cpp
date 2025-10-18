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

void deleteFirst(List &L, address &p) {
    if (L.First != nullptr) {
        p = L.First;
        L.First = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &p) {
    if (L.First == nullptr) {
        p = nullptr;
    } else if (L.First->next == nullptr) {
        p = L.First;
        L.First = nullptr;
    } else {
        address q = L.First;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

void deleteAfter(List &L, address prec, address &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

int nbList(List L) {
    int count = 0;
    address p = L.First;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    address p;
    while (L.First != nullptr) {
        deleteFirst(L, p);
        dealokasi(p);
    }
}
