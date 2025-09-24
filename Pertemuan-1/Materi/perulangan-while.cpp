#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "Masukan angka 1 : ";
    cin >> angka1;

    int i = 0;
    int j = 11;

    while (i < angka1){
        cout << i << " - ";
        i++;
    };

    cout << endl;

    do{
        cout << j << " - ";
        j++;
    } while (j < angka1);
    
    return 0;
}