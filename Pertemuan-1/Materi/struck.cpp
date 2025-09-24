#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct rapot{
        string nama;
        int nilai;
    };

    rapot siswa[jumlah];
    for (int i = 0; i < jumlah; i++){
        cout << "Masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int i = 0;
    while (i < jumlah) {
        cout << "Nama siswa : " << siswa[i].nama << " nilai : " << siswa[i].nilai << endl;
        i++;
    };
    
    return 0;
}