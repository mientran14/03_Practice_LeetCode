class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        // Hàng đầu [1]; mỗi hàng i có i+1 phần tử, 2 biên là 1; phần tử giữa = prev[j-1] + prev[j]
        for (int i = 0; i < numRows; i++) {
            triangle.push_back(vector<int>(i+1, 1));
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        return triangle;
    }
};