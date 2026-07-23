class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        auto getDist = [](int x1, int y1, int x2, int y2) {
            return abs(x1-x2) + abs(y1-y2);
        };

        int minCost = getDist(start[0], start[1], target[0], target[1]);

        // Bỏ specialRoads dư thừa 
        vector<vector<int>> validRoads;
        for (auto& r : specialRoads) {
            int normalDist = getDist(r[0], r[1], r[2], r[3]);
            int specialCost = r[4];
            
            if (specialCost < normalDist) validRoads.push_back(r);
        }

        int n = validRoads.size();
        if (n == 0) return minCost;

        vector<int> dist(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // start -> nodeS1 -> nodeE1
        for (int i = 0; i < n; i++) {
            dist[i] = getDist(start[0], start[1], validRoads[i][0], validRoads[i][1]) + validRoads[i][4];
            pq.push({dist[i], i});
        }

        // Dijkstra
        while (!pq.empty()) {
            auto [currDist, currRoad] = pq.top();
            pq.pop();

            if (currDist > dist[currRoad]) continue;

            int endX = validRoads[currRoad][2];
            int endY = validRoads[currRoad][3];

            minCost = min(minCost, currDist + getDist(endX, endY, target[0], target[1]));

            for (int nextR = 0; nextR < n; ++nextR) {
                int newCost = currDist + getDist(endX, endY, validRoads[nextR][0], validRoads[nextR][1]) + validRoads[nextR][4];
                
                if (newCost < dist[nextR]) {
                    dist[nextR] = newCost;
                    pq.push({newCost, nextR});
                }
            }
        }

        return minCost;
    }
};