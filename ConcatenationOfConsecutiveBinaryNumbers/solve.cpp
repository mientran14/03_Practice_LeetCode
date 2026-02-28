class Solution {
public:
    int concatenatedBinary(int n) {
        long long result = 0;
        const int MOD = 1e9 + 7;
        int countbit = 0;

        for (int i = 1; i <= n; i++) {
            if ((i & (i-1)) == 0) countbit++;
            result = ((result << countbit) + i) % MOD;
        }

        return result;
    }
};