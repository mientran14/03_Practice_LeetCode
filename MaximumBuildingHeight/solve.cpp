class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            int distLR = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + distLR);
        }

        for (int i = m - 2; i >= 0; i--) {
            int distRL = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + distRL);
        }

        // peak = high1 + dist1 
        // peak = high2 + dist2 = dist - dist1
        // => 2*peak = high1 + high2 + dist1 + dist - dist1
        // => peak = (high1 + high2 + dist)/2

        int peak = 0;
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            int h1 = restrictions[i-1][1];
            int h2 = restrictions[i][1];
            peak = max(peak, (h1 + h2 + dist)/2);
        }

        return peak;
    }
};