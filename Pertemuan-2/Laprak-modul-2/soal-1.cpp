#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3;j++) {
            cout << arr[i][j] << " ";
        }
            cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {2, 6, 8},
        {3, 5 ,1},
        {4, 8, 2}
    };
    int arrB[3][3] = {
        {1, 3, 3},
        {3, 2 ,0},
        {3, 4, 1}
    };  
    
    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    // Penjumlahan
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    // Pengurangan
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil Pengurungan : " << endl;
    tampilkanHasil(arrD);
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {   
            for (int k = 0; k < 3; k++) {
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil Perkalian : " << endl;
    tampilkanHasil(arrE);

    return 0;
}