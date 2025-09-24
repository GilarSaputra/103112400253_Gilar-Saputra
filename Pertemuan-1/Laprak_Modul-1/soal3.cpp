#include <iostream>
using namespace std;

int main() {
    int n;    cout << "Input : ";
    cin >> n;

    cout << "Output : " << endl;

    for (int i = n; i >= 1 ; i--) {
        for (int spasi = 0; spasi < (n - i); spasi++) {
            cout << "  "; 
        }
        for (int sisiKiri = i; sisiKiri >= 1; sisiKiri--){            
            cout << sisiKiri << " ";
        }

        cout << " * ";

        for (int sisiKanan = 1; sisiKanan <= i; sisiKanan++){
            cout << sisiKanan << " ";
        }
        
        cout << endl;  
    }
    
    for (int lastSpasi = 0; lastSpasi < n; lastSpasi++) {
        cout << "  ";
    }
    cout << " * " << endl;
    return 0;
    
}