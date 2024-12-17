#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Position {
    double longitude;
    double latitude;
};

void ajouterVille(unordered_map<string, Position>& villes, const string& nom, double longitude, double latitude) {
    villes[nom] = {longitude, latitude};
}

Position rechercherVille(const unordered_map<string, Position>& villes, const string& nom) {
    auto it = villes.find(nom);
    if (it != villes.end()) {
        return it->second;
    }
    return {0, 0};
}

int main() {
    unordered_map<string, Position> villes;
    ajouterVille(villes, "Tunis", 10.16579, 36.81897);
    ajouterVille(villes, "Sfax", 10.758, 34.7406);

    string recherche;
    cout << "Entrez le nom de la ville : ";
    cin >> recherche;

    auto resultat = rechercherVille(villes, recherche);
    if (resultat.longitude != 0 || resultat.latitude != 0) {
        cout << "Ville trouvée : " << recherche
             << ", Longitude : " << resultat.longitude
             << ", Latitude : " << resultat.latitude << endl;
    } else {
        cout << "Ville non trouvée." << endl;
    }
    return 0;
}
