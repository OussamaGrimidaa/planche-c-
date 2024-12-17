#include <iostream>
#include <vector>
using namespace std;

void afficherPositif(int& x, int seuil = 0) {
    if (x >= 0) cout << x << " ";
}

void afficherNegatif(int& x, int seuil = 0) {
    if (x < 0) cout << x << " ";
}

void afficherSuperieur(int& x, int seuil) {
    if (x >= seuil) cout << x << " ";
}

void appliquerFiltre(vector<int>& vec, void(*filtre)(int&, int)) {
    int seuil = 0;
    if (filtre == afficherSuperieur) {
        cout << "Donner le seuil : ";
        cin >> seuil;
    }
    for (int& e : vec) {
        filtre(e, seuil);
    }
    cout << endl;
}

int main() {
    vector<int> tab = {-2, 3, -33, 7, 99, 6, 2, -39};
    cout << "************************\n";
    cout << "* 1. Afficher positif *\n";
    cout << "* 2. Afficher negatif *\n";
    cout << "* 3. Afficher supérieur à un seuil *\n";
    cout << "************************\n";
    cout << "Entrez votre choix : ";
    int choix;
    cin >> choix;

    switch (choix) {
        case 1: appliquerFiltre(tab, afficherPositif); break;
        case 2: appliquerFiltre(tab, afficherNegatif); break;
        case 3: appliquerFiltre(tab, afficherSuperieur); break;
        default: cout << "Choix invalide." << endl; break;
    }

    return 0;
}
