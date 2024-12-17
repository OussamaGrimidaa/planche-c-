#include <iostream>
using namespace std;

void convertir() {
    double valeur;
    char choix;
    cout << "Entrez 'K' pour convertir de km vers miles ou 'M' pour miles vers km : ";
    cin >> choix;
    cout << "Entrez la valeur : ";
    cin >> valeur;

    if (choix == 'K' || choix == 'k') {
        cout << valeur << " km = " << valeur / 1.609 << " miles." << endl;
    } else if (choix == 'M' || choix == 'm') {
        cout << valeur << " miles = " << valeur * 1.609 << " km." << endl;
    } else {
        cout << "Choix invalide." << endl;
    }
}

int main() {
    convertir();
    return 0;
}
