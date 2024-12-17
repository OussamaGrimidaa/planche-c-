#include <iostream>
using namespace std;

class Vecteur {
protected:
    double x, y;
public:
    Vecteur() : x(0), y(0) {}
    Vecteur(double x, double y) : x(x), y(y) {}
    void afficher() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Vecteur3D : public Vecteur {
    double z;
public:
    Vecteur3D() : Vecteur(), z(0) {}
    Vecteur3D(double x, double y, double z) : Vecteur(x, y), z(z) {}
    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
    void deplacer(double dx, double dy, double dz) {
        Vecteur::deplacer(dx, dy);
        z += dz;
    }
};

int main() {
    Vecteur v1;
    cout << "Vecteur nul : ";
    v1.afficher();

    v1.deplacer(2.5, 3.0);
    cout << "Vecteur déplacé : ";
    v1.afficher();

    Vecteur3D* v2 = new Vecteur3D(1.0, 2.0, 3.0);
    cout << "Vecteur3D créé : ";
    v2->afficher();

    v2->deplacer(1.0, -1.0, 0.5);
    cout << "Vecteur3D déplacé : ";
    v2->afficher();

    delete v2;
    return 0;
}
