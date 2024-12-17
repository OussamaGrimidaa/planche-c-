#include <iostream>
using namespace std;

template <typename T>
void echanger(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void trier(T tab[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < taille; j++) {
            if (tab[j] < tab[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            echanger(tab[i], tab[minIndex]);
        }
    }
}

int main() {
    int tableauInt[10] = {5, 2, 9, 1, 5, 6, 3, 7, 4, 8};
    cout << "Tableau d'entiers avant tri : ";
    for (int val : tableauInt) {
        cout << val << " ";
    }
    cout << endl;

    trier(tableauInt, 10);

    cout << "Tableau d'entiers après tri : ";
    for (int val : tableauInt) {
        cout << val << " ";
    }
    cout << endl;

    double tableauDouble[10] = {1.1, 3.3, 0.5, 2.2, 4.4, 1.5, 3.8, 0.9, 2.7, 4.1};
    cout << "Tableau de doubles avant tri : ";
    for (double val : tableauDouble) {
        cout << val << " ";
    }
    cout << endl;

    trier(tableauDouble, 10);

    cout << "Tableau de doubles après tri : ";
    for (double val : tableauDouble) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
