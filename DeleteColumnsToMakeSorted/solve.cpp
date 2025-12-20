class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int nrow = strs.size();
        int ncol = strs[0].size();
        int result = 0;

        for (int j = 0; j < ncol; j++) {
            for (int i = 0; i < nrow-1; i++) {
                if (strs[i][j] > strs[i+1][j]) {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};
