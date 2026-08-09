class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int suffixSum = 0;

        for (int i = n-1; i >= 0; i--) {
            suffixSum += piles[i];

            for (int m = 1; m <= n; m++) {
                if (i + 2*m >= n) {
                    dp[i][m] = suffixSum;
                } 
                else {
                    int minNext = INT_MAX;
                    for (int x = 1; x <= 2*m; x++) {
                        minNext = min(minNext, dp[i + x][max(m, x)]);
                    }
                    dp[i][m] = suffixSum - minNext;
                }
            }
        }

        return dp[0][1];
    }
};