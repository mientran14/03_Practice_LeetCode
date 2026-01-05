class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minAbsElement = INT_MAX;
        int negaCount = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] < 0) negaCount++;
                sum += abs(matrix[i][j]);
                minAbsElement = min(minAbsElement, abs(matrix[i][j]));
            }
        }
        if (negaCount % 2 != 0) {
            sum = sum - 2 * minAbsElement;
        }
        return sum;
    }
};