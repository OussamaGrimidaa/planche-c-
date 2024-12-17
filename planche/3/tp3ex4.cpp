#include <iostream>
#include <vector>
using namespace std;

pair<int, int> mini_maxi(const vector<int>& A) {
    if (A.empty()) {
        cout << "Le tableau est vide !" << endl;
        return {0, 0};
    }

    int min_val = A[0];
    int max_val = A[0];

    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
    }

    return {min_val, max_val};
}

int main() {

    vector<int> A = {3, 5, 1, 9, 2, -4, 7};
    pair<int, int> resultat = mini_maxi(A);
    cout << "Valeur minimale : " << resultat.first << endl;
    cout << "Valeur maximale : " << resultat.second << endl;

    return 0;
}
