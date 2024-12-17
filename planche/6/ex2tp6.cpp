#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
class Robot {
protected:
    string nom;
    double x, y, portee;
    bool estMort;

public:
    Robot(const string& nom, double x = 0, double y = 0, double portee = 0)
        : nom(nom), x(x), y(y), portee(portee), estMort(false) {}

    void deplacer(double dx, double dy) { x += dx; y += dy; }

    void afficher() const {
            cout << "Nom: " << nom << ", Position: (" << x << ", " << y
                  << "), Portee: " << portee << ", Statut: "
                  << (estMort ? "Mort" : "Vivant") << "\n";
    }

    bool estALaPortee(const Robot& autre) const {
        return !autre.estMort && hypot(x - autre.x, y - autre.y) <= portee;
    }

    void tuer(Robot& autre) {
        if (estALaPortee(autre)) {
            autre.estMort = true;
                cout << autre.nom << " est mort.\n";
        }
    }
};

class RobotChasseur : public Robot {
public:
    RobotChasseur(const string& nom, double x, double y, double portee)
        : Robot(nom, x, y, portee) {}

    void traquerEtTuer(vector<Robot>& robots) {
        for (auto& robot : robots)
            tuer(robot);
    }
};

int main() {
    RobotChasseur optimus("Optimus", 2, 3, 25);
    optimus.deplacer(33, 19);
    optimus.afficher();

    vector<Robot> robots = {
        Robot("zbadnda9loush", 30, 20, 0),
        Robot("chichi", 5, 5, 0),
        Robot("effectone", 10, 10, 0),
        Robot("dragonfire", 40, 25, 0),
        Robot("entraineur", 35, 22, 0)
    };

    for (auto& robot : robots)
        robot.afficher();

    optimus.traquerEtTuer(robots);

    for (auto& robot : robots)
        robot.afficher();

    return 0;
}
