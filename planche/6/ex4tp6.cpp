#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Piece {
protected:
    string couleur;
    int x, y;

public:
    Piece(string couleur, int x, int y) : couleur(couleur), x(x), y(y) {}

    virtual void deplacer(int dx, int dy) = 0;

    virtual void afficher() const {
        cout << "Type: " << typeid(*this).name()
             << " | Couleur: " << couleur
             << " | Position: (" << x << ", " << y << ")\n";
    }

    bool estHorsLimites(int x, int y) const {
        return x < 1 || x > 8 || y < 1 || y > 8;
    }
};

class Pion : public Piece {
public:
    Pion(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer(int dx, int dy) override {
        if (dy == 1 && dx == 0) {
            y += dy;
            if (estHorsLimites(x, y)) y -= dy;
        }
    }
};

class Roi : public Piece {
public:
    Roi(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer(int dx, int dy) override {
        if (abs(dx) <= 1 && abs(dy) <= 1) {
            x += dx;
            y += dy;
            if (estHorsLimites(x, y)) {
                x -= dx;
                y -= dy;
            }
        }
    }
};

int main() {
    vector<Piece*> pieces;
    pieces.push_back(new Pion("Blanc", 1, 2));
    pieces.push_back(new Pion("Noir", 3, 5));
    pieces.push_back(new Pion("Blanc", 7, 7));
    pieces.push_back(new Roi("Noir", 4, 4));

    for (const auto& piece : pieces) piece->afficher();

    pieces[0]->deplacer(0, 1);
    pieces[1]->deplacer(1, 0);
    pieces[3]->deplacer(1, 1);
    pieces[3]->deplacer(2, 2);

    for (const auto& piece : pieces) piece->afficher();

    for (auto& piece : pieces) delete piece;

    return 0;
}

