// // https://wiki.vnoi.info/algo/data-structures/disjoint-set-union
// // https://viblo.asia/p/disjoint-set-union-dsu-union-find-part-1-OQJwzz8y4MP
// class UnionFind {
// public:
//     vector<int> parent;
    
//     UnionFind(int size) {
//         parent.resize(size);
//     }

//     void make_set(int v) {
//         parent[v] = v;
//     }

//     int find_set(int v) {
//         if (v == parent[v]) return v;
//         return find_set(parent[v]);
//     }

//     bool union_set(int x, int y) {
//         x = find_set(x);
//         y = find_set(y);
//         if (x != y) {
//             parent[x] = y; 
//             return false;
//         }
//         else return true;
//     }
// };

// class Solution {
// public:
//     int m, n;
//     // Convert 2DIdx into 1D Idx
//     int getIdx(int x, int y) {
//         return x*n + y;
//     }

//     bool containsCycle(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         UnionFind uf(m*n);

//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 uf.make_set(getIdx(i, j));

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (j+1 < n && grid[i][j] == grid[i][j+1]) {
//                     int curr = getIdx(i, j);
//                     int right = getIdx(i, j+1);
//                     if (uf.union_set(curr, right)) return true;
//                 }

//                 if (i+1 < m && grid[i][j] == grid[i+1][j]) {
//                     int curr = getIdx(i, j);
//                     int down = getIdx(i+1, j);
//                     if (uf.union_set(curr, down)) return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        auto checkCell = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        function<bool(int, int, int, int, char)> dfs = [&](int x, int y, int px, int py, char val) {
            visited[x][y] = true;

            for (auto [dx, dy] : dirs) {
                int nx = x+dx, ny = y+dy;

                if (checkCell(nx, ny) && grid[nx][ny] == val) {
                    if (nx == px && ny == py) continue; // SKIP previous cell
                    if (visited[nx][ny]) return true;
                    if (dfs(nx, ny, x, y, val)) return true;
                }
            }
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j])) return true;
                }
            }
        }

        return false;
    }
};