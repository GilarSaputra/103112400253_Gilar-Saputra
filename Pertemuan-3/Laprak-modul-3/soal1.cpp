#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    const int jumlahMhs = 10;
    Mahasiswa mhs[jumlahMhs];
    int i = 0;

    cout << "=== Input Data Mahasiswa (maks 10) ===" << endl;
    cout << "Masukkan NIM = 0 untuk berhenti." << endl;

    while (i < jumlahMhs) {
        cout << "\nNIM : ";
        cin >> mhs[i].nim;

        if (mhs[i].nim == 0) {
            break; 
        }

        cin.ignore(); 
        cout << "Nama : ";
        getline(cin, mhs[i].nama);

        cout << "Nilai UTS : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;
        cout << "---------------------" << endl;

        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);

        i++;
    }

    cout << "\nDaftar Nilai Mahasiswa" << endl;
    cout << "==============================" << endl;

    for (int j = 0; j < i; j++) {
        cout << j + 1 << ". NIM: " << mhs[j].nim
            << ", Nama: " << mhs[j].nama
            << ", Nilai Akhir: " << mhs[j].nilaiAkhir << endl;
    }

    return 0;
}
