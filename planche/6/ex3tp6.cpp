#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    static int num_s; // S�rie globale
    static int num_v_s; // Num�ro global dans la s�rie
    int annee;
    double prix;
    int serie; // S�rie du v�hicule
    int num;   // Num�ro du v�hicule dans la s�rie

public:
    Vehicule(int annee, double prix)
        : annee(annee), prix(prix) {
        if (num_v_s == 10000) {
            num_s++;
            num_v_s = 1;
        }
        serie = num_s;
        num = num_v_s++;
    }

    virtual void accelerer() const = 0;

    void afficher() const {
        cout << serie << " TUN " << num
             << " | Annee: " << annee
             << " | Prix: " << prix << " DT\n";
    }
};

int Vehicule::num_s = 192;
int Vehicule::num_v_s = 9988;

class Voiture : public Vehicule {
private:
    int nbre_place;

public:
    Voiture(int annee, double prix, int nbre_place)
        : Vehicule(annee, prix), nbre_place(nbre_place) {}

    void accelerer() const override {
        cout << "Je peux atteindre 200km/h.\n";
    }

    void afficher() const {
        Vehicule::afficher();
        cout << "Nombre de places: " << nbre_place << "\n";
    }
};

class Camion : public Vehicule {
private:
    double chargeMaximale;

public:
    Camion(int annee, double prix, double chargeMaximale)
        : Vehicule(annee, prix), chargeMaximale(chargeMaximale) {}

    void accelerer() const override {
        cout << "Je peux atteindre 120km/h.\n";
    }

    void afficher() const {
        Vehicule::afficher();
        cout << "Charge maximale: " << chargeMaximale << " tonnes\n";
    }
};

int main() {
    Voiture v1(2023, 90000, 5);
    Camion c1(2024, 150000, 12);

    cout << "D�tails de la voiture:\n";
    v1.afficher();
    v1.accelerer();

    cout << "\nD�tails du camion:\n";
    c1.afficher();
    c1.accelerer();

    return 0;
}
