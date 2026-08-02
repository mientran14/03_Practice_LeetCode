class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // refer: https://leetcode.com/problems/predict-the-winner
        int n = piles.size();
        vector<int> dp(piles);                           // diff [i, j]

        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                int pickLeft = piles[i] - dp[j];         // Opt1: lấy số đầu piles[i]
                int pickRight = piles[j] - dp[j-1];      // Opt2: lấy số cuối piles[j]
                dp[j] = max(pickLeft, pickRight);
            }
        }
        
        return dp[n - 1] >= 0;
    }
};