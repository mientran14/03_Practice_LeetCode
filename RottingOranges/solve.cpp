class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> rotten;
        int fresh = 0;
        int result = 0;

        vector<pair<int, int>> direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) rotten.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        while (!rotten.empty() && fresh > 0) {
            int s = rotten.size(); // rotten.size() thay đổi mỗi khi rotten.push() -> lưu trước size ban đầu
            for (int i = 0; i < s; ++i) {
                auto [x, y] = rotten.front();
                rotten.pop();

                for (auto [dx, dy] : direct) {
                    int nx = x + dx, ny = y + dy;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                        fresh--;
                    }
                }
            }
            result++;
        }

        return fresh == 0 ? result : -1;
    }
};