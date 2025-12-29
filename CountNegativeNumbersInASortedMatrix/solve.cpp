class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int result = 0;
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[i].size(); j++) {
        //         if (grid[i][j] < 0) result++;
        //     }
        // }
        // return result;

        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (grid[i][mid] < 0) right = mid - 1;
                else  left = mid + 1;
            }
            result += (n - left);
        }
        return result;
    }
};
