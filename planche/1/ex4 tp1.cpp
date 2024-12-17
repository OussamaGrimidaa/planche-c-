#include <iostream>
#include <cmath>
using namespace std;

double distance(double xa, double ya, double xb, double yb) {
    return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
}

void testerDistance() {
    double xa, ya, xb, yb;
    cout << "Entrez les coordonnees de A (xa, ya) : ";
    cin >> xa >> ya;
    cout << "Entrez les coordonnees de B (xb, yb) : ";
    cin >> xb >> yb;

    cout << "La distance AB est : " << distance(xa, ya, xb, yb) << endl;
}

int main() {
    testerDistance();
    return 0;
}
