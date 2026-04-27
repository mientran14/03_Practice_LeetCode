class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        unordered_map<int, vector<pair<int, int>>> map = {
            {1, {{0, -1}, {0, 1}}},
            {2, {{-1, 0}, {1, 0}}},
            {3, {{0, -1}, {1, 0}}},
            {4, {{0, 1}, {1, 0}}},
            {5, {{-1, 0}, {0, -1}}},
            {6, {{-1, 0}, {0, 1}}}
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        auto checkCell = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i == m-1 && j == n-1) return true;

            visited[i][j] = true;

            for (auto [dx, dy] : map[grid[i][j]]) {
                int ni = i+dx, nj = j+dy;
                if (checkCell(ni, nj) && !visited[ni][nj]) {
                    for (auto [rdx, rdy] : map[grid[ni][nj]]) {
                        if (rdx == -dx && rdy == -dy) {
                            if (dfs(ni, nj)) return true;
                            break;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(0, 0);
    }
};