#include <iostream>
#include <cmath>
using namespace std;

double f(double x, bool& OK) {
    if (x >= 1 && x <= 2) {
        OK = true;
        return sqrt((x - 1) * (2 - x));
    } else {
        OK = false;
        return 0;
    }
}

void testerF() {
    double x;
    bool OK;
    cout << "Entrez une valeur pour x : ";
    cin >> x;

    double resultat = f(x, OK);
    if (OK) {
        cout << "f(" << x << ") = " << resultat << endl;
    } else {
        cout << "La fonction n'est pas definie pour x = " << x << endl;
    }
}

int main() {
    testerF();
    return 0;
}
