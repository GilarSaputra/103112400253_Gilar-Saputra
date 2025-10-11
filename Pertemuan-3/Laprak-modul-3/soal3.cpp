#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void menukarIsi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void ubahDenganPointer(int *ptr1, int *ptr2, int nilaiBaru1, int nilaiBaru2) {
    *ptr1 = nilaiBaru1;  // ubah nilai pertama melalui pointer pertama
    *ptr2 = nilaiBaru2;  // ubah nilai kedua melalui pointer kedua
}

int main() {
    int arrA[3][3] = {
        {12, 2, 8},
        {8, 11, 6},
        {7, 8, 5}
    };

    int arrB[3][3] = {
        {9, 2, 23},
        {1, 1, 1},
        {8, 4, 3}
    };

    cout << "=== Array A ===" << endl;
    tampilArray(arrA);
    cout << "=== Array B ===" << endl;
    tampilArray(arrB);

    int baris = 1, kolom = 1;
    menukarIsi(arrA, arrB, baris, kolom);

    cout << "\n=== Setelah Penukaran ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(arrA);
    cout << "Array B:" << endl;
    tampilArray(arrB);

    cout << "\n=== Ubah Dua Nilai Array A dengan Dua Pointer ===" << endl;
    int barisPtr1 = 0, kolomPtr1 = 1;
    int barisPtr2 = 2, kolomPtr2 = 0;

    int *ptr1 = &arrA[barisPtr1][kolomPtr1];
    int *ptr2 = &arrA[barisPtr2][kolomPtr2];

    cout << "Sebelum diubah: arrA[" << barisPtr1 << "][" << kolomPtr1 << "] = " << *ptr1 
         << ", arrA[" << barisPtr2 << "][" << kolomPtr2 << "] = " << *ptr2 << endl;

    ubahDenganPointer(ptr1, ptr2, 15, 12);

    cout << "Setelah diubah melalui dua pointer:" << endl;
    cout << "arrA[" << barisPtr1 << "][" << kolomPtr1 << "] = " << arrA[barisPtr1][kolomPtr1] << endl;
    cout << "arrA[" << barisPtr2 << "][" << kolomPtr2 << "] = " << arrA[barisPtr2][kolomPtr2] << endl;

    cout << "\n=== Array A Sekarang ===" << endl;
    tampilArray(arrA);

    return 0;
}
