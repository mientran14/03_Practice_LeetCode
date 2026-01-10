class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();

        // vector<vector<int>> dp(s1, vector<int>(s2, INT_MIN));
        // dp[0][0] = nums1[0] * nums2[0];

        // // Wrong Answer 62/69 testcases passed
        // // Need to fix
        // for (int i = 0; i < s1; i++) {
        //     for (int j = 0; j < s2; j++) {
        //         if (i == 0 && j == 0) {
        //             dp[i][j] = nums1[i] * nums2[j];
        //         } 
        //         else if (i == 0) {
        //             dp[i][j] = max(dp[i][j-1], nums1[i] * nums2[j]);
        //         }
        //          else if (j == 0) {
        //             dp[i][j] = max(dp[i-1][j], nums1[i] * nums2[j]);
        //         } 
        //         else {
        //             int case1 = dp[i-1][j-1] + nums1[i] * nums2[j];
        //             int case2 = dp[i-1][j];
        //             int case3 = dp[i][j-1];
        //             dp[i][j] = max({case1, case2, case3});
        //         }
        //     }
        // }
        // return dp[s1-1][s2-1];

        vector<vector<int>> memo(s1, vector<int>(s2, INT_MIN));

        function<int(int, int)> F = [&](int i1, int i2) -> int {
            if (i1 < 0 || i2 < 0) {
                return INT_MIN;
            }
            if (memo[i1][i2] != INT_MIN) {
                return memo[i1][i2];
            }

            int cur_prod = nums1[i1] * nums2[i2];
            memo[i1][i2] = max({
                cur_prod,
                F(i1 - 1, i2),
                F(i1, i2 - 1),
                cur_prod + (F(i1 - 1, i2 - 1) != INT_MIN ? F(i1 - 1, i2 - 1) : 0)
            });

            return memo[i1][i2];
        };

        return F(s1 - 1, s2 - 1);
    }
};
