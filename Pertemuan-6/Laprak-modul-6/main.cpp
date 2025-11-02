#include "Doublylist.h"

bool findNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Kendaraan k;
        cout << "\nmasukkan nomor polisi: ";
        cin >> k.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> k.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> k.thnBuat;

        if (findNopol(L, k.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            address P = alokasi(k);
            insertLast(L, P);
        }
    }

    printInfo(L);

    // Nomor 2: Cari elemen
    Kendaraan cari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != NULL) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan!" << endl;
    }

    // Nomor 3: Hapus elemen
    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address P = L.First;
    while (P != NULL && P->info.nopol != hapusNopol) {
        P = P->next;
    }

    if (P == NULL) {
        cout << "Data tidak ditemukan!" << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
        dealokasi(P);
    }

    printInfo(L);
    return 0;
}
