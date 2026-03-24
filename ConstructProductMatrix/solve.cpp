class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;

        vector<vector<int>> result(n, vector<int>(m, 0));

        // suffix product
        // https://www.geeksforgeeks.org/dsa/suffix-product-array/
        long long suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                result[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        // prefix product
        // https://www.geeksforgeeks.org/dsa/prefix-product-array/
        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (result[i][j] * prefix) % MOD; // except for the element grid[i][j]
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        return result;
    }
};