class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }

        // Wrong Answer: 929/942 testcases passed
        // Need to improve the logic to check "remain connected" condition.

        if (m > 1) {
            long long rowPrefixSum = 0;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    rowPrefixSum += grid[i][j];
                }
                long long bottomSum = totalSum - rowPrefixSum;

                if (rowPrefixSum == bottomSum) return true;
                else {
                    for (int j = 0; j < n; j++) {
                        if (rowPrefixSum == bottomSum - grid[i + 1][j]) {
                            return true;
                        }
                    }
                }
            }
        }

        if (n > 1) {
            long long colPrefixSum = 0;
            for (int j = 0; j < n - 1; j++) {
                for (int i = 0; i < m; i++) {
                    colPrefixSum += grid[i][j];
                }
                long long rightSum = totalSum - colPrefixSum;

                if (colPrefixSum == rightSum) return true;
                else {
                    for (int i = 0; i < m; i++) {
                        if (colPrefixSum == rightSum - grid[i][j + 1]) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};