class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        // Example 1: grid = [[0, 1],[2, 0]], k = 1
        //     (0,0) -> (0,1)
        //       ↓        ↓
        //     (1,0) -> (1,1)
        //         (0,0): score = 0, costs = 0
        //         (0,1): score = 1, costs = 1
        //         (1,0): score = 2, costs = 1
        //         (1,1): score = 0, costs = 0
        //     maxScore((0,0)->(0,1)->(1,1), (0,0)->(1,0)->(1,1))

    //..............................................................................
        // // TLE 4/529 testcases passed
        // int m = grid.size(), n = grid[0].size();
        // vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
        // function<int(int, int, int)> dfs = [&](int i, int j, int cost) {
        //     if (cost > k) return -1;
        //     if (i == m-1 && j == n-1) return grid[i][j];
        //     int maxScore = -1;
        //     for (auto [di, dj] : dirs) {
        //         int ni = i+di, nj = j+dj;
        //         if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
        //             int newCost = cost + (grid[ni][nj] > 0 ? 1 : 0);
        //             int score = dfs(ni, nj, newCost);
        //             if (score != -1) {
        //                 maxScore = max(maxScore, score + grid[i][j]);
        //             }
        //         }
        //     }
        //     return maxScore;
        // };
        // return dfs(0, 0, 0);
        
    //..............................................................................
        // // Using Memoization -> TLE 249/529 testcases passed
        // int m = grid.size(), n = grid[0].size();
        // vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
        // // memo[i][j][cost]
        // vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        // function<int(int, int, int)> dfs = [&](int i, int j, int cost) {
        //     if (cost > k) return -1;
        //     if (i == m-1 && j == n-1) return grid[i][j];

        //     if (memo[i][j][cost] != -1) return memo[i][j][cost];

        //     int maxScore = -1;
        //     for (auto [di, dj] : dirs) {
        //         int ni = i+di, nj = j+dj;
        //         if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
        //             int newCost = cost + (grid[ni][nj] > 0 ? 1 : 0);
        //             int score = dfs(ni, nj, newCost);
        //             if (score != -1) {
        //                 maxScore = max(maxScore, score + grid[i][j]);
        //             }
        //         }
        //     }

        //     return memo[i][j][cost] = maxScore;
        // };
        // return dfs(0, 0, 0);

    //..............................................................................
        // Using Tabulation
        // https://www.geeksforgeeks.org/dsa/tabulation-vs-memoization/
        int m = grid.size(), n = grid[0].size();
        // dp[i][j][cost]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        dp[0][0][0] = 0;
        if(grid[0][0] > 0) dp[0][0][1] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    if (i+1 < m) {
                        int newCost = c + (grid[i+1][j] > 0 ? 1 : 0);
                        if (newCost <= k) {
                            dp[i+1][j][newCost] = max(dp[i+1][j][newCost], dp[i][j][c] + grid[i+1][j]);
                        }
                    }

                    if (j+1 < n) {
                        int newCost = c + (grid[i][j+1] > 0 ? 1 : 0);
                        if (newCost <= k) {
                            dp[i][j+1][newCost] = max(dp[i][j+1][newCost], dp[i][j][c] + grid[i][j+1]);
                        }
                    }
                }
            }
        }

        int maxScore = -1;
        for (int cost = 0; cost <= k; cost++) {
            maxScore = max(maxScore, dp[m-1][n-1][cost]);
        }

        return maxScore;
    }
};