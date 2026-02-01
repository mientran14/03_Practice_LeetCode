class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        int result = 0;

        // Wrong Answer 73 / 658 testcases passed
        // Need to fix

        // grid[i][j] == grid[i + 1][j]
        for (int j = 0; j < n; j++) {
            vector<int> fcol(10, 0);
            for (int i = 0; i < m; i++) fcol[grid[i][j]]++;
            result += m - *max_element(fcol.begin(), fcol.end());
        }

        // grid[i][j] != grid[i][j + 1]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n-1; j++) {
                if (grid[i][j] == grid[i][j + 1]) {
                    grid[i][j+1] = -1;
                    result++;
                }
            }
        }

        return result;
    }
};