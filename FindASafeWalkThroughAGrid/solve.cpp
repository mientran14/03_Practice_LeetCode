class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> maxH(m, vector<int>(n, -1));

        int startH = health - grid[0][0];
        if (startH <= 0) return false;

        queue<array<int, 3>> q;
        q.push({0, 0, startH});
        maxH[0][0] = startH;

        int dirs[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [x, y, currH] = q.front();
            q.pop();

            if (x == m-1 && y == n-1) return true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int remainH = currH - grid[nx][ny];
                    if (remainH > 0 && remainH > maxH[nx][ny]) {
                        maxH[nx][ny] = remainH;
                        q.push({nx, ny, remainH});
                    }
                }
                
            }
        }
        return false;
    }
};