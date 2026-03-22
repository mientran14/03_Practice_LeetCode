class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        auto rotate = [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < mat.size(); j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n/2; j++) {
                    swap(mat[i][j], mat[i][n - 1 - j]);
                }
            }
        };

        // 0/90/180/270 degree
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotate();
        }

        return false;
    }
};