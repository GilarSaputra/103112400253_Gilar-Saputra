#ifndef GRAPHKOTA_H
#define GRAPHKOTA_H

#include <iostream>
#include <string>
using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namaKota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct GraphKota {
    adrKota First;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string namaKota);
adrEdge alokasiEdge(adrKota kotaTujuan, int jarak);
void insertNode(GraphKota &G, string namaKota);
adrKota findNode(GraphKota G, string namaKota);
void connectNode(GraphKota &G, string kotaAsal, string kotaTujuan, int jarak);
void disconnectNode(GraphKota &G, string kotaAsal, string kotaTujuan);
void deleteNode(GraphKota &G, string namaKota);
void printGraph(GraphKota G);

#endif