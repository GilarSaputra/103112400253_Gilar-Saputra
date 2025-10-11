// Header guard digunakan untuk mencegah file header yang sama
// di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

// declarasi ADT pelajaran 
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// function untukmembuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel);

// prosedur untuk menapilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif