class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> count(n, vector<int>(11, 0)); // 0 <= yi <= 10
        int result = 0;
        
        for (auto& p : pick) {
            int player = p[0];
            int color = p[1];
            count[player][color]++;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int color = 0; color <= 10; color++) {
                if (count[i][color] >= i + 1) {
                    result++;
                    break;
                }
            }
        }
        
        return result;
    }
};
