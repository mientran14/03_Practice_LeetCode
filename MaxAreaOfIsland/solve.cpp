class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        int curArea = 0;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true; 
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            curArea++;
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true; 
                    q.push({nx, ny});
                }
            }
        }
        
        return curArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, bfs(grid, visited, i, j));
                }
            }
        }
        
        return maxArea;
    }
};