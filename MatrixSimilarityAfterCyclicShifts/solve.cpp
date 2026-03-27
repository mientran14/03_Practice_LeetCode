class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        vector<vector<int>> tmp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    tmp[i][(j + n - k) % n] = mat[i][j];
                } else {
                    tmp[i][(j + k) % n] = mat[i][j];
                }
            }
        }

        return tmp == mat;
    }
};