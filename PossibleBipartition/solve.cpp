class Solution {
public:
    // dfs theo hướng tô màu đồ thị
    bool dfs(int node, int c, vector<int>& color, const vector<vector<int>>& graph) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == c) return false;
            
            if (color[neighbor] == 0) {
                if (!dfs(neighbor, -c, color, graph)) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (const auto& d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                if (!dfs(i, 1, color, graph)) return false;
            }
        }

        return true;
    }
};