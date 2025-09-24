#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    // Penjumlahan
    cout << "Penjumlahan : " << angka1+ angka2 << endl;
    // Pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    // Perkalian 
    cout << "Perkalian : "<< angka1 * angka2 << endl;
    // Pembagian 
    cout << "Pembagia :" << angka1 / angka2 << endl;
    // mOdulus
    cout << "Modulus : " << angka1 % angka2 << endl;
    return 0;
}
