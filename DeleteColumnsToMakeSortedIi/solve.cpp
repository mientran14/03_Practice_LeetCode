class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int nrow = strs.size();
        int ncol = strs[0].size();
        int result = 0;
        vector<string> sortedrow(nrow, "");

        for (int j = 0; j < ncol; ++j) {
            vector<string> tmp = sortedrow;
            for (int i = 0; i < nrow; ++i) {
                tmp[i] += strs[i][j];
            }

            bool isSorted = true;
            for (int i = 0; i < nrow - 1; ++i) {
                if (tmp[i] > tmp[i + 1]) {
                    isSorted = false;
                    break;
                }
            }

            if (!isSorted) {
                result++;
            } else {
                sortedrow = tmp;
            }
        }

        return result;
    }
};
