class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Q.đường ngang tính từ đầu hàng i: (j + k) --> (j + k)%n -> quay vòng chỉ số cột
                int newC = (j + k) % n;
                int newR= (i + (j + k) / n) % m;
                result[newR][newC] = grid[i][j];
            }
        }

        return result;
    }
};