#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void afficherTableau(const vector<int>& tab) {
    for (int val : tab) {
        cout << val << " ";
    }
    cout << endl;
}

void trierTableau(vector<int>& tab) {
    sort(tab.begin(), tab.end());
}

pair<int, int> mini_maxi(const vector<int>& tab) {
    if (tab.empty()) return {0, 0};  // Cas où le tableau est vide
    int min_val = *min_element(tab.begin(), tab.end());
    int max_val = *max_element(tab.begin(), tab.end());
    return {min_val, max_val};
}

int sommeTableau(const vector<int>& tab) {
    int somme = 0;
    for (int val : tab) {
        somme += val;
    }
    return somme;
}

int main() {
    vector<int> tab = {3, 1, 4, 1, 5, 9};

    cout << "Tableau original : ";
    afficherTableau(tab);

    trierTableau(tab);
    cout << "Tableau trié : ";
    afficherTableau(tab);

    auto [min_val, max_val] = mini_maxi(tab);
    cout << "Min : " << min_val << ", Max : " << max_val << endl;

    cout << "Somme des éléments : " << sommeTableau(tab) << endl;

    return 0;
}
