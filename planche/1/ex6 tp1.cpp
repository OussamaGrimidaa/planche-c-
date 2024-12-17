#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void testerSwap() {
    int a, b;
    cout << "Entrez deux entiers a et b : ";
    cin >> a >> b;

    cout << "Avant l'echange : a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "Apres l'echange : a = " << a << ", b = " << b << endl;
}

int main() {
    testerSwap();
    return 0;
}
