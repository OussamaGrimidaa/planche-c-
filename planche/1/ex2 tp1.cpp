#include <iostream>
using namespace std;

void trouverMin() {
    int minVal = INT_MAX, valeur;
    cout << "Entrez 10 entiers :\n";
    for (int i = 0; i < 10; ++i) {
        cin >> valeur;
        if (valeur < minVal) {
            minVal = valeur;
        }
    }
    cout << "Le plus petit entier est : " << minVal << endl;
}

int main() {
    trouverMin();
    return 0;
}
