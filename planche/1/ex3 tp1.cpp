#include <iostream>
#include <string>
using namespace std;

void trouverMotPlusLong() {
    int n;
    cout << "Entrez le nombre de mots : ";
    cin >> n;
    string mot, motPlusLong;

    cout << "Entrez les mots :\n";
    for (int i = 0; i < n; ++i) {
        cin >> mot;
        if (mot.length() > motPlusLong.length()) {
            motPlusLong = mot;
        }
    }
    cout << "Le mot le plus long est : " << motPlusLong << endl;
}

int main() {
    trouverMotPlusLong();
    return 0;
}
