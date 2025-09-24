#include <iostream>
using namespace std;

int main() {
    string satuan[] = {
        "", " satu", " dua", " tiga", " empat", " lima", " enam", " tujuh", " delapan", " sembilan"
    };
    string belasan[] = {
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas",
        "tujuh belas", "delapan belas", "sembilan belas"
    };
    string puluhan[] = {
        "", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", 
        "delapan puluh", "sembilan puluh"
    };

    int bil;

    cout << "Masukan angka : ";
    cin >> bil;

    string hasil = "";

    if (bil == 0) {
        hasil = "nol";
    };
    if (bil == 100){ 
        hasil = "seratus";
    }


    if (bil < 10) {
        hasil = satuan[bil];
    }
    else if ( bil < 20 ) {
        hasil = belasan[bil-10];
    }
    else {
        hasil = puluhan[bil/10];
        if (bil % 10 != 0) 
        {
            hasil += "" + satuan[bil%10];
        }    
    }

    cout << bil << " : " << hasil << endl;
    return 0;
}