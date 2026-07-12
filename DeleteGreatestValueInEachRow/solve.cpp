class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for (auto& row : grid) {
            sort(row.begin(), row.end());
        }

        for (int c = 0; c < n; c++) {
            int maxVal = 0;
            for (int r = 0; r < m; r++) {
                maxVal = max(maxVal, grid[r][c]);
            }
            result += maxVal;
        }

        return result;
    }
};