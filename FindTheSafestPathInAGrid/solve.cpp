class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // S1: Tìm độ an toàn của từng cell
        // Use: Muilti-source BFS

        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && safeness[nx][ny] == -1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // S2&3: Tim path có độ an toàn max (độ an toàn của mỗi path là min cell trong path đó)
        // Use: max-heap

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        maxHeap.push({safeness[0][0], {0, 0}});
        visited[0][0] = true;
        
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            
            int pathsafe = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            if (x == n-1 && y == n-1) return pathsafe;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int new_pathsafe = min(pathsafe, safeness[nx][ny]);
                    maxHeap.push({new_pathsafe, {nx, ny}});
                }
            }
        }
        
        return 0;
    }
};