class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<int> sumRow(m, 0);
        vector<int> sumCol(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    sumRow[i]++;
                    sumCol[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && sumRow[i] == 1 && sumCol[j] == 1) result++;
            }
        }

        return result;
    }
};