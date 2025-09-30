#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 30, b = 45, c = 100;

    cout << "Sebelum swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    tukar(a, b, c);

    cout << "Setelah sapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
