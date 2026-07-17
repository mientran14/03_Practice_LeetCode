class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int result = 0;

        function<bool(int, int)> dfs = [&](int r, int c) -> bool {
            if (r < 0 || r >= m || c < 0 || c >= n || grid2[r][c] == 0)  return true;

            grid2[r][c] = 0;

            bool subIsland = (grid1[r][c] == 1);

            bool up    = dfs(r - 1, c);
            bool down  = dfs(r + 1, c);
            bool left  = dfs(r, c - 1);
            bool right = dfs(r, c + 1);

            return subIsland && up && down && left && right;
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid2[r][c] == 1) {
                    if (dfs(r, c)) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};