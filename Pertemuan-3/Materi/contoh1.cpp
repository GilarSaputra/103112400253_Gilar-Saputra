#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(Mahasiswa &m) {
    cout << "Masukan nama mahasiswa :" ;
    cin >> m.nama;
    cout << "Masukan nilai 1 :";
    cin >> m.nilai1;   
    cout << "Masukan nilai 2 :";
    cin >> m.nilai2;
}

float rata2(Mahasiswa m) {
    return((m.nilai1 + m.nilai2)/2);
}

int main() {
    Mahasiswa mhs;  //memangil struct ADT
    inputMhs(mhs);  // memanggil prosedur inptMHS
    cout << "Rata-rata : " << rata2(mhs);   // memanggil function rata2
    return 0;
}