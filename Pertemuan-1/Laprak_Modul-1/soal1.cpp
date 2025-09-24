#include <iostream>
using namespace std;

int main() {
    float b1, b2;
    cout << "Masukan bilangan 1 : ";
    cin >> b1;
    cout << "Masukan bilangan 2 : ";
    cin >> b2;

    cout << "Hasil Penjumlahan " << b1 << " + " << b2 << " = " << b1 + b2 << endl;
    cout << "Hasil Pengurangan " << b1 << " - " << b2 << " = " << b1 - b2 << endl;
    cout << "Hasil Perkalian " << b1 << " * " << b2 << " = " << b1 * b2 << endl;
    cout << "Hasil Pembagain " << b1 << " / " << b2 << " = " << b1 / b2 << endl;
    return 0;
}