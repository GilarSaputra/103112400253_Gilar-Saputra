#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent kosong" << endl;
    } else {
        NodeParent temp = LParent.first;
        LParent.first = LParent.first->next;
        if (LParent.first != NULL) {
            LParent.first->prev = NULL;
        } else {
            LParent.last = NULL;
        }
        deleteListChild(temp->L_Child);
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeParent toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    deleteListChild(toDelete->L_Child);
    deallocNodeParent(toDelete);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) {
        cout << "List Child kosong" << endl;
    } else {
        NodeChild temp = LChild.first;
        LChild.first = LChild.first->next;
        if (LChild.first != NULL) {
            LChild.first->prev = NULL;
        } else {
            LChild.last = NULL;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev == NULL || NPrev->next == NULL) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }
    NodeChild toDelete = NPrev->next;
    NPrev->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    deallocNodeChild(toDelete);
}

void printMLLStructure(listParent &LParent) {
    nodeParent* P = LParent.first;
    int parentCount = 1;
    
    while (P != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child) == true) {
            cout << "(tidak ada child)" << endl;
        } else {
            nodeChild* C = P->L_Child.first;
            int childCount = 1;
            
            while (C != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                
                cout << "    Ekor : ";
                if (C->isidata.ekor == true) {
                    cout << "1";
                } else {
                    cout << "0";
                }
                cout << endl;
                
                cout << "    Bobot : " << C->isidata.bobot << endl;
                
                C = C->next;
                childCount = childCount + 1;
            }
        }
        
        P = P->next;
        parentCount = parentCount + 1;
        cout << "-------------------------" << endl;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    nodeParent* P = LParent.first;
    int nomorParent = 1;
    bool adaHasil = false;
    
    while (P != NULL) {
        nodeChild* C = P->L_Child.first;
        int nomorChild = 1;
        
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                adaHasil = true;
                
                cout << "Data ditemukan pada list anak dari node parent ";
                cout << P->isidata.namaGolongan << " pada posisi ke-" << nomorChild << "!" << endl;
                cout << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << nomorChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "---" << endl;
                cout << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << nomorParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "---" << endl;
                cout << endl;
                cout << endl;
            }
            C = C->next;
            nomorChild = nomorChild + 1;
        }
        P = P->next;
        nomorParent = nomorParent + 1;
    }
    
    if (adaHasil == false) {
        cout << "Tidak ada hewan yang ditemukan dengan kriteria pencarian." << endl;
    }
}