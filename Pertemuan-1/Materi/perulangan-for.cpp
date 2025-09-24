#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    for (int i = 0; i <= angka1; i++) // increment
    {
        cout << i << " - ";
    
    }

    cout << endl;
    
    // for (int i = angka1; i >= 0; i--) // decrement
    // {
    //     cout << i << " - ";
    // }

    for (int i = 20; i >= angka2; i--) //decrement
    {
        cout << i << " - ";
    }

    return 0;
}