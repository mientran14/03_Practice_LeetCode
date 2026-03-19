class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        int result = 0;

        vector<vector<int>> prefix_X(m, vector<int>(n, 0));
        vector<vector<int>> prefix_Y(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix_X[i][j] = (grid[i][j] == 'X' ? 1 : 0);
                prefix_Y[i][j] = (grid[i][j] == 'Y' ? 1 : 0);

                if (i > 0) {
                    prefix_X[i][j] += prefix_X[i-1][j];
                    prefix_Y[i][j] += prefix_Y[i-1][j];
                } 
                if (j > 0) {
                    prefix_X[i][j] += prefix_X[i][j-1];
                    prefix_Y[i][j] += prefix_Y[i][j-1];
                } 
                if (i > 0 && j > 0) {
                    prefix_X[i][j] -= prefix_X[i-1][j-1];
                    prefix_Y[i][j] -= prefix_Y[i-1][j-1];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count_X = prefix_X[i][j];
                int count_Y = prefix_Y[i][j];
                if (count_X == count_Y && count_X > 0) result++;
            }
        }
        
        return result;
    }
};