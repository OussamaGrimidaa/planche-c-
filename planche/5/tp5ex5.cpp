#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    void afficher() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

class Cercle {
private:
    double rayon;
    Point centre;

public:
    Cercle(double rayon, const Point& centre) : rayon(rayon), centre(centre) {}
    Cercle(double rayon, double x, double y) : rayon(rayon), centre(x, y) {}

    void afficher() const {
        cout << "Cercle de rayon: " << rayon << " et centre: ";
        centre.afficher();
    }

    double getRayon() const { return rayon; }
    Point getCentre() const { return centre; }

    void setRayon(double r) { rayon = r; }
    void setCentre(const Point& p) { centre = p; }

    void translater(double dx, double dy) {
        centre.setX(centre.getX() + dx);
        centre.setY(centre.getY() + dy);
    }

    double surface() const {
        return M_PI * rayon * rayon;
    }

    double perimetre() const {
        return 2 * M_PI * rayon;
    }

    bool estEgal(const Cercle& autre) const {
        return rayon == autre.rayon && centre.getX() == autre.centre.getX() && centre.getY() == autre.centre.getY();
    }

    bool contientPoint(const Point& p) const {
        double distance = sqrt(pow(p.getX() - centre.getX(), 2) + pow(p.getY() - centre.getY(), 2));
        return distance <= rayon;
    }
};

int main() {
    // Cr�ation d'un cercle avec un rayon de 1 et un centre (10, 10)
    Cercle c1(1, Point(10, 10));

    // Affichage des caract�ristiques du cercle
    cout << "Caract�ristiques du cercle initial : " << endl;
    c1.afficher();

    // Calcul et affichage de la surface et du p�rim�tre
    cout << "Surface du cercle: " << c1.surface() << endl;
    cout << "P�rim�tre du cercle: " << c1.perimetre() << endl;

    // Doublement du rayon
    c1.setRayon(c1.getRayon() * 2);
    cout << "\nApr�s doublement du rayon:" << endl;

    // Affichage du p�rim�tre et de la surface apr�s modification
    cout << "Surface du cercle: " << c1.surface() << endl;
    cout << "P�rim�tre du cercle: " << c1.perimetre() << endl;

    // D�placement du cercle pour ramener son centre � l'origine
    c1.translater(-c1.getCentre().getX(), -c1.getCentre().getY());
    cout << "\nApr�s translation du cercle � l'origine : " << endl;
    c1.afficher();

    // V�rification de l'appartenance des points
    Point p1(1, 1), p2(3, 3);

    cout << "\nLe point (1, 1) est-il � l'int�rieur du cercle ? ";
    cout << (c1.contientPoint(p1) ? "Oui" : "Non") << endl;

    cout << "Le point (3, 3) est-il � l'int�rieur du cercle ? ";
    cout << (c1.contientPoint(p2) ? "Oui" : "Non") << endl;

    // Test de l'�galit� avec un autre cercle
    Cercle c2(2, Point(0, 0));
    cout << "\nLe cercle est-il �gal � un cercle de centre (0, 0) et de rayon 2 ? ";
    cout << (c1.estEgal(c2) ? "Oui" : "Non") << endl;

    return 0;
}

