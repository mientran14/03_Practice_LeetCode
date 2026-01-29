class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long result = 0;
        int INF = 1e8;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int org = original[i] - 'a';
            int chg = changed[i] - 'a';
            dist[org][chg] = min(dist[org][chg], cost[i]);
        }

        // Floyd Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < source.size(); i++) {
            int src = source[i] - 'a';
            int tg = target[i] - 'a';
            if (dist[src][tg] == INF) return -1;
            result += dist[src][tg];
        }

        return result;
    }
};