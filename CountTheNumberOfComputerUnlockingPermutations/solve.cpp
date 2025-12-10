class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;
        int minval = INT_MAX;
        for (int i = 1; i < complexity.size(); i++) {
            minval = min(minval, complexity[i]);
        }

        if (complexity[0] >= minval) {
            return 0;
        }

        long long result = 1;

        for (int i=1; i<=(complexity.size()-1); i++) {
            result = (result * i) % MOD; // Tính hoán vị
        }

        return result;
    }
};