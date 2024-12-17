#include <iostream>
#include <string>
using namespace std;

struct Produit {
    string type;
    double prixHT;
    bool solde;
};

double calculerPrix(const Produit& produit) {
    double taxe = (produit.type == "luxe") ? 0.25 : 0.19;
    double prixTTC = produit.prixHT * (1 + taxe);

    if (produit.solde) {
        prixTTC *= 0.8; // Réduction de 20% pour les soldes
    }

    return prixTTC;
}

int main() {
    Produit p1 = {"normal", 100, false};
    Produit p2 = {"luxe", 200, true};
    Produit p3 = {"normal", 50, true};

    cout << "Produit 1 (type: " << p1.type << ", prix HT: " << p1.prixHT << ", soldé: " << (p1.solde ? "oui" : "non") << "): "
         << calculerPrix(p1) << " EUR" << endl;

    cout << "Produit 2 (type: " << p2.type << ", prix HT: " << p2.prixHT << ", soldé: " << (p2.solde ? "oui" : "non") << "): "
         << calculerPrix(p2) << " EUR" << endl;

    cout << "Produit 3 (type: " << p3.type << ", prix HT: " << p3.prixHT << ", soldé: " << (p3.solde ? "oui" : "non") << "): "
         << calculerPrix(p3) << " EUR" << endl;

    return 0;
}
