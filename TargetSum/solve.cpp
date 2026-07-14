class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // S(+), D(-)
        // S - D = target
        // S + D = T
        // S - D + S + D = 2S = target + T 
        // => S = (target + T)/2

        int total = 0;
        for (int n : nums) total += n;
        if (abs(target) > total || (target + total) % 2 != 0) return 0;

        int sub = (target + total)/2;
        vector<int> dp(sub+1, 0);
        dp[0] = 1;

        for (int n : nums) {
            for (int j = sub; j >= n; j--) {
                dp[j] += dp[j - n];
            }
        }

        return dp[sub];
    }
};