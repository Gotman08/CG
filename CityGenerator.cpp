#include "CityGenerator.h"

namespace CG {

    // Constructor
    CityGenerator::CityGenerator(int n)
        : City(n, std::vector<int>(n, 0)),
          randomGenerator(std::random_device{}()),
          distribution(0, 1)
    {
    }

    // Fill the city grid with random values (0 or 1)
    void CityGenerator::remplire() {
        for (int i = 0; i < City.size(); i++) {
            for (int j = 0; j < City[i].size(); j++) {
                City[i][j] = distribution(randomGenerator);
            }
        }
    }

    // Generate city (private method)
    void CityGenerator::GenerateCity() {
        for (int i = 0; i < City.size(); i++) {
            for (int j = 0; j < City[i].size(); j++) {
                verification(City, i, j);
            }
        }
    }

    // Verification method with bug fixes
    bool CityGenerator::verification(const std::vector<std::vector<int>>& t, int i, int j) {
        bool res = false;  // Bug fix: added declaration

        // Bug fix: corrected the conditional logic with proper parentheses
        if ((i != 0 && j != 0) ||
            (i != 0 && j != (t[i].size() - 1)) ||
            (i == (t.size() - 1) && j == 0) ||
            (i == (t.size() - 1) && j == (t[i].size() - 1))) {

            switch (i) {
                case 0:
                    res = (t[i][j] == t[i+1][j] &&
                           t[i][j] == t[i+1][j-1] &&
                           t[i][j] == t[i][j-1] &&
                           t[i][j] == t[i][j+1] &&
                           t[i][j] == t[i+1][j+1]);
                    break;
                case 1:
                    res = (t[i][j] == t[i+1][j] &&
                           t[i][j] == t[i+1][j-1] &&
                           t[i][j] == t[i][j-1] &&
                           t[i][j] == t[i][j+1] &&
                           t[i][j] == t[i+1][j+1] &&
                           t[i][j] == t[i-1][j] &&
                           t[i][j] == t[i-1][j-1] &&
                           t[i][j] == t[i-1][j+1]);
                    break;
                case 2:
                default:
                    break;
            }
        }

        return res;  // Bug fix: added return statement
    }

    // Getter for the city grid
    const std::vector<std::vector<int>>& CityGenerator::getCity() const {
        return City;
    }

} // namespace CG
