#include <iostream>
using namespace std;

int factoriel(int N) {
    int resultat = 1;
    for (int i = 1; i <= N; ++i) {
        resultat *= i;
    }
    return resultat;
}

void testerFactoriel() {
    int N;
    cout << "Entrez un entier N : ";
    cin >> N;

    cout << "Le factoriel de " << N << " est : " << factoriel(N) << endl;
}

int main() {
    testerFactoriel();
    return 0;
}
