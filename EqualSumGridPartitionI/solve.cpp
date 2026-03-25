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

        if (totalSum % 2 != 0) return false;

        if (m > 1) {
            long long rowPrefixSum = 0;
            for (int i = 0; i < m-1; i++) {
                for (int j = 0; j < n; j++) {
                    rowPrefixSum += grid[i][j];
                }
                if (rowPrefixSum == totalSum/2) return true;
            }
        }

        if (n > 1) {
            long long colPrefixSum = 0;
            for (int j = 0; j < n-1; j++) {
                for (int i = 0; i < m; i++) {
                    colPrefixSum += grid[i][j];
                }
                if (colPrefixSum == totalSum/2) return true;
            }
        }

        return false;
    }
};