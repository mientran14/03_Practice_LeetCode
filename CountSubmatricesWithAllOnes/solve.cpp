class Solution {
public:
    // Need to improve
    
    int findLeftBoundary(const vector<int>& row, int col) {
        while (col >= 0 && row[col] == 1) col--;
        return col + 1;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int minWidth = INT_MAX;

                    for (int k = i; k >= 0; k--) {
                        if (mat[k][j] == 0) break;
                        minWidth = min(minWidth, j - findLeftBoundary(mat[k], j) + 1);
                        result += minWidth;
                    }
                }
            }
        }

        return result;
    }
};