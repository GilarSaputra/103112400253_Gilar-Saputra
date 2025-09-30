#include <iostream>
using namespace std;

int cariMaksimum(int arrA[], int ukuran) {
    int MAX = arrA[0];
    for (int i = 1; i < ukuran; i++) {
        if (arrA[i] > MAX) {
            MAX = arrA[i];
        }
    }
    return MAX;
}

int cariMinimum(int arrA[], int ukuran) {
    int MIN = arrA[0];
    for (int i = 1; i < ukuran; i++) {
        if (arrA[i] < MIN) {
            MIN = arrA[i];
        }
    }
    return MIN;
}

void hitungRataRata(int arr[], int ukuran) {
    int sum = 0;
    for (int i = 0; i < ukuran; i++) {
        sum += arr[i];
    }
    double rata = (double)sum / ukuran;
    cout << "Nilai rata-rata = " << rata << endl;
}

void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int ukuran = 10; // jumlah elemen array
    int arrA[ukuran] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int input;

        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "Pilih menu: ";
        cin >> input;

        switch (input) {
            case 1:
                tampilkanArray(arrA, ukuran);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    return 0;
}
