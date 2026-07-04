class Solution {
public:
    // Refer to https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (k >= m + n - 2) return m + n - 2; // (m - 1 - 0) + (n - 1 - 0)

        vector<vector<int>> maxK(m, vector<int>(n, -1));

        queue<array<int, 4>> q; // x, y, currK, steps
        
        q.push({0, 0, k, 0});
        maxK[0][0] = k;

        int dirs[] = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            auto [x, y, currK, steps] = q.front();
            q.pop();

            if (x == m-1 && y == n-1) return steps;

            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int remainK = currK - grid[nx][ny];
                    
                    if (remainK >= 0 && remainK > maxK[nx][ny]) {
                        maxK[nx][ny] = remainK;
                        q.push({nx, ny, remainK, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};