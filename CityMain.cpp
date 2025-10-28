#include <iostream>
#include <vector>
#include "CityGenerator.h"

using namespace std;
using namespace CG;

// Display function to print the 2D city grid
void afficher(const vector<vector<int>>& t) {
    for (int i = 0; i < t.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < t[i].size(); j++) {
            if (j != t[i].size() - 1) {
                cout << t[i][j] << ", ";
            } else {
                cout << t[i][j] << " ]";
            }
        }
        cout << endl;
    }
}

// Main entry point
int main() {
    CityGenerator CG(4);
    CG.remplire();
    afficher(CG.getCity());

    return 0;
}
