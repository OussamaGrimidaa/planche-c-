#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Ville {
    string nom;
    double longitude;
    double latitude;
};

void ajouterVille(vector<Ville>& villes, const string& nom, double longitude, double latitude) {
    villes.push_back({nom, longitude, latitude});
}

Ville rechercherVille(const vector<Ville>& villes, const string& nom) {
    for (const auto& ville : villes) {
        if (ville.nom == nom) {
            return ville;
        }
    }
    return {"", 0, 0};
}

int main() {
    vector<Ville> villes;
    ajouterVille(villes, "Tunis", 10.16579, 36.81897);
    ajouterVille(villes, "Sfax", 10.758, 34.7406);

    string recherche;
    cout << "Entrez le nom de la ville : ";
    cin >> recherche;

    Ville resultat = rechercherVille(villes, recherche);
    if (resultat.nom != "") {
        cout << "Ville trouvée : " << resultat.nom
             << ", Longitude : " << resultat.longitude
             << ", Latitude : " << resultat.latitude << endl;
    } else {
        cout << "Ville non trouvée." << endl;
    }
    return 0;
}
