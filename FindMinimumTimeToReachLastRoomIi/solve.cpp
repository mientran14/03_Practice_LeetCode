class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        minHeap.push({0, 0, 0});
        dist[0][0] = 0;
        
        vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int curTime = curr[0];
            int x = curr[1];
            int y = curr[2];
            
            if (x == n-1 && y == m-1) return curTime;
            if (curTime > dist[x][y]) continue;

            int stepTime = ((x + y) % 2) + 1;

            for (auto [dx, dy] : direc) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nextTime = max(curTime, moveTime[nx][ny]) + stepTime;

                    if (nextTime < dist[nx][ny]) {
                        dist[nx][ny] = nextTime;
                        minHeap.push({nextTime, nx, ny});
                    }
                }
            }
        }
        
        return -1;
    }
};