class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // Wrong Answer 105 / 717 testcases passed

        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        q.push({0, {0, 0}});
        visited[0][0] = 0;
        
        while (!q.empty()) {
            auto [curTime, pos] = q.front();
            int x = pos.first;
            int y = pos.second;
            q.pop();
            
            if (x == n-1 && y == m-1) return curTime;

            for (auto [dx, dy] : direc) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nextTime = curTime + 1;
                    if ((curTime + 1) % 2 == 0) nextTime++;
                    
                    if (nextTime < moveTime[nx][ny]) {
                        nextTime = moveTime[nx][ny];
                        if ((nextTime - curTime) % 2 == 0) nextTime++;
                    }
                    
                    if (nextTime < visited[nx][ny]) {
                        visited[nx][ny] = nextTime;
                        q.push({nextTime, {nx, ny}});
                    }
                }
            }
        }
        
        return -1;
    }
};