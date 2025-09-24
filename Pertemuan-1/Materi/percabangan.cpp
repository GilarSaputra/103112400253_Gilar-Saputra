#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << angka1 << " Lebih besar dari " << angka2 << endl;
    } else if (angka1 == angka2){
        cout << angka1 << " Sama dengan " << angka2 << endl;
    } else if ( angka1 < angka2 ) {
        cout << angka1 << " Lebih kecil dari " << angka2 << endl;
    }
    
    
    if (angka1 != angka2){
        cout << angka1 << " Tidak Sama dengan " << angka2 << endl;
    }

    return 0;
}