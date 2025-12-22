#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct DataFilm {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTerbit;
    float ratingFilm;
};

struct GenreFilm {
    string idGenre;
    string namaGenre;
    string deskripsi;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataFilm isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    GenreFilm isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

NodeParent alokasiNodeParent(string idGenre, string namaGenre, string deskripsi);
NodeChild alokasiNodeChild(string idFilm, string judulFilm, int durasi, int tahun, float rating);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void hapusListAnak(listAnak &LAnak);

void searchFilmByRatingRange(listInduk &LInduk, float minRating, float maxRating);
void printStrukturMLL(listInduk &LInduk);

#endif