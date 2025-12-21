class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        char col1 = s[0], col2 = s[3];
        int row1 = s[1] - '0', row2 = s[4] - '0';
        for (char c = col1; c <= col2; c++) {
            for (int r = row1; r <= row2; r++) {
                result.push_back(string(1, c) + to_string(r));
            }
        }
        return result;
    }
};