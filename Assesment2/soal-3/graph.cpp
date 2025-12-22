#include "graph.h"

void createGraph(GraphKota &G) {
    G.First = nullptr;
}

adrKota alokasiNode(string namaKota) {
    adrKota newNode = new ElmKota;
    newNode->namaKota = namaKota;
    newNode->visited = 0;
    newNode->firstEdge = nullptr;
    newNode->next = nullptr;
    return newNode;
}

adrEdge alokasiEdge(adrKota kotaTujuan, int jarak) {
    adrEdge newEdge = new ElmEdge;
    newEdge->kotaTujuan = kotaTujuan;
    newEdge->jarak = jarak;
    newEdge->next = nullptr;
    return newEdge;
}

void insertNode(GraphKota &G, string namaKota) {
    adrKota newNode = alokasiNode(namaKota);
    if (G.First == nullptr) {
        G.First = newNode;
    } else {
        adrKota last = G.First;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
}

adrKota findNode(GraphKota G, string namaKota) {
    adrKota current = G.First;
    while (current != nullptr) {
        if (current->namaKota == namaKota) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void connectNode(GraphKota &G, string kotaAsal, string kotaTujuan, int jarak) {
    adrKota nodeAsal = findNode(G, kotaAsal);
    adrKota nodeTujuan = findNode(G, kotaTujuan);
    
    if (nodeAsal == nullptr || nodeTujuan == nullptr) return;
    
    adrEdge edgeAsalToTujuan = alokasiEdge(nodeTujuan, jarak);
    adrEdge edgeTujuanToAsal = alokasiEdge(nodeAsal, jarak);
    
    if (nodeAsal->firstEdge == nullptr) {
        nodeAsal->firstEdge = edgeAsalToTujuan;
    } else {
        adrEdge lastEdge = nodeAsal->firstEdge;
        while (lastEdge->next != nullptr) {
            lastEdge = lastEdge->next;
        }
        lastEdge->next = edgeAsalToTujuan;
    }
    
    if (nodeTujuan->firstEdge == nullptr) {
        nodeTujuan->firstEdge = edgeTujuanToAsal;
    } else {
        adrEdge lastEdge = nodeTujuan->firstEdge;
        while (lastEdge->next != nullptr) {
            lastEdge = lastEdge->next;
        }
        lastEdge->next = edgeTujuanToAsal;
    }
}

void disconnectNode(GraphKota &G, string kotaAsal, string kotaTujuan) {
    adrKota nodeAsal = findNode(G, kotaAsal);
    adrKota nodeTujuan = findNode(G, kotaTujuan);
    
    if (nodeAsal == nullptr || nodeTujuan == nullptr) return;
    
    adrEdge prev = nullptr;
    adrEdge current = nodeAsal->firstEdge;
    while (current != nullptr) {
        if (current->kotaTujuan == nodeTujuan) {
            if (prev == nullptr) {
                nodeAsal->firstEdge = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
    
    prev = nullptr;
    current = nodeTujuan->firstEdge;
    while (current != nullptr) {
        if (current->kotaTujuan == nodeAsal) {
            if (prev == nullptr) {
                nodeTujuan->firstEdge = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
}

void deleteNode(GraphKota &G, string namaKota) {
    adrKota nodeToDelete = findNode(G, namaKota);
    if (nodeToDelete == nullptr) return;
    
    adrKota current = G.First;
    adrKota prev = nullptr;
    while (current != nullptr) {
        disconnectNode(G, current->namaKota, namaKota);
        current = current->next;
    }
    
    current = G.First;
    prev = nullptr;
    while (current != nullptr && current != nodeToDelete) {
        prev = current;
        current = current->next;
    }
    
    if (prev == nullptr) {
        G.First = nodeToDelete->next;
    } else {
        prev->next = nodeToDelete->next;
    }
    
    adrEdge edgeCurrent = nodeToDelete->firstEdge;
    while (edgeCurrent != nullptr) {
        adrEdge edgeTemp = edgeCurrent;
        edgeCurrent = edgeCurrent->next;
        delete edgeTemp;
    }
    
    delete nodeToDelete;
}

void printGraph(GraphKota G) {
    adrKota currentKota = G.First;
    while (currentKota != nullptr) {
        cout << currentKota->namaKota << " : ";
        adrEdge currentEdge = currentKota->firstEdge;
        while (currentEdge != nullptr) {
            cout << "-> " << currentEdge->kotaTujuan->namaKota 
                << " (" << currentEdge->jarak << " km) ";
            currentEdge = currentEdge->next;
        }
        cout << endl;
        currentKota = currentKota->next;
    }
}