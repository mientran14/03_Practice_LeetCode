class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        minHeap.push({0, 0, 0, 0}); // {time, x, y, state}
        dist[0][0][0] = 0;
        
        vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int curTime = curr[0];
            int x = curr[1];
            int y = curr[2];
            int state = curr[3];
            
            if (x == n-1 && y == m-1) return curTime;
            if (curTime > dist[x][y][state]) continue;

            for (auto [dx, dy] : direc) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int stepTime = (state == 0) ? 1 : 2;
                    int nextTime = max(curTime, moveTime[nx][ny]) + stepTime;
                    int nextState = state^1; // nhớ đảo state lại

                    if (nextTime < dist[nx][ny][nextState]) {
                        dist[nx][ny][nextState] = nextTime;
                        minHeap.push({nextTime, nx, ny, nextState});
                    }
                }
            }
        }
        
        return -1;
    }
};