#include <iostream>
#include <vector>
using namespace std;

int produitScalaire(const vector<int>& U, const vector<int>& V) {
    if (U.size() != V.size()) {
        cout << "Les vecteurs doivent avoir la même dimension !" << endl;
        return -1;
    }

    int produit = 0;
    for (size_t i = 0; i < U.size(); i++) {
        produit += U[i] * V[i];
    }
    return produit;
}

int main() {
    vector<int> U = {1, 2, 3};
    vector<int> V = {4, 5, 6};

    int resultat = produitScalaire(U, V);
    if (resultat != -1) {
        cout << "Le produit scalaire de U et V est : " << resultat << endl;
    }

    return 0;
}
