#pragma once

#include <vector>
#include <random>

namespace CG {

    class CityGenerator {
    private:
        static constexpr int Street = 0;
        static constexpr int Home = 1;
        std::vector<std::vector<int>> City;
        std::mt19937 randomGenerator;
        std::uniform_int_distribution<int> distribution;

        // Private methods
        void GenerateCity();
        bool verification(const std::vector<std::vector<int>>& t, int i, int j);

    public:
        // Constructor
        explicit CityGenerator(int n);

        // Public methods
        void remplire();
        const std::vector<std::vector<int>>& getCity() const;
    };

} // namespace CG
