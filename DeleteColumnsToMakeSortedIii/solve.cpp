class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int nrow = strs.size();
        int ncol = strs[0].size();
        vector<int> dp(ncol, 1);

        for (int col = 1; col < ncol; col++) {
            for (int precol = 0; precol < col; precol++) {
                bool valid = true;
                for (int row = 0; row < nrow; row++) {
                    if (strs[row][precol] > strs[row][col]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[col] = max(dp[col], dp[precol] + 1);
                }
            }
        }

        int maxLIS = *max_element(dp.begin(), dp.end());
        return ncol - maxLIS;
    }
};