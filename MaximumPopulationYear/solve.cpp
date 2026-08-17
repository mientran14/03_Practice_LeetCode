class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop(2051, 0);

        for (auto& log : logs) {
            for (int year = log[0]; year < log[1]; ++year) {
                pop[year]++;
            }
        }

        int earlyYear = 1950;
        for (int year = 1950; year <= 2050; ++year) {
            if (pop[year] > pop[earlyYear]) {
                earlyYear = year;
            }
        }

        return earlyYear;
    }
};