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

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {12, 2, 8},
        {8, 11, 6},
        {7, 8, 5}
    };

    int B[3][3] = {
        {9, 2, 23},
        {1, 1, 1},
        {8, 4, 3}
    };

    cout << "=== Array A ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B ===" << endl;
    tampilArray(B);

    int baris = 1, kolom = 2;
    cout << "\nMenukar elemen pada posisi [" << baris << "][" << kolom << "]" << endl;
    menukarIsi(A, B, baris, kolom);

    cout << "\n=== Setelah Penukaran ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
