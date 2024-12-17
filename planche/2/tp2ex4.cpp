#include <iostream>
using namespace std;


int add(int x, int y) {
    return x + y;
}

int sous(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int dive(int x, int y) {
    if (y == 0) {
        cout << "Erreur : Division par zéro !" << endl;
        return 0;
    }
    return x / y;
}

int main() {
    int a, b;

    cout << "Entrez deux nombres : ";
    cin >> a >> b;

      int choix;

    do {
        cout << "\nChoisissez une operation : " << endl;
        cout << "1. Addition" << endl;
        cout << "2. Soustraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Quitter" << endl;
        cout << "Entrez le numéro de l'operation : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Résultat de " << a << " + " << b << " = " << add(a, b) << endl;
                break;
            case 2:
                cout << "Résultat de " << a << " - " << b << " = " << sous(a, b) << endl;
                break;
            case 3:
                cout << "Résultat de " << a << " * " << b << " = " << mul(a, b) << endl;
                break;
            case 4:
                cout << "Résultat de " << a << " / " << b << " = " << dive(a, b) << endl;
                break;
            case 5:
                cout << "Vous avez choisi de quitter." << endl;
                system("cls");
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
                break;
        }

    } while (choix != 5);



    return 0;
}
