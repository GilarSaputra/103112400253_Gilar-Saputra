#include "pelajaran.h"

//implementasi function vreate-pelajaran
pelajaran create_pelajaran(string namaMapel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodePel;
    return p;
}

// implementasi prosedu tampilan_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran: " << pel.namaMapel << endl;
    cout << "nilai: " << pel.kodeMapel << endl;
}