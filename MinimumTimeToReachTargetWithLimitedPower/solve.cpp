class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<long long>> dp(n, vector<long long>(power + 1, -1));
        dp[source][power] = 0;

        for (int p = power; p >= 0; p--) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int t = edge[2];

                if (dp[u][p] != -1 && p >= cost[u]) {
                    int next_p = p - cost[u];
                    long long new_time = dp[u][p] + t;

                    if (dp[v][next_p] == -1 || new_time < dp[v][next_p]) {
                        dp[v][next_p] = new_time;
                    }
                }
            }
        }

        long long min_time = -1;
        int max_power = -1;

        for (int p = 0; p <= power; ++p) {
            if (dp[target][p] != -1) {
                if (min_time == -1 || dp[target][p] < min_time) {
                    min_time = dp[target][p];
                    max_power = p;
                } 
                else if (dp[target][p] == min_time) {
                    max_power = max(max_power, p);
                }
            }
        }

        if (min_time == -1) return {-1, -1};
        
        return {min_time, max_power};  
    }
};