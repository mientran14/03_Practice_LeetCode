class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int curWidth = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (curWidth + w > 100) {
                lines++;
                curWidth = w;
            } else curWidth += w;
        }
        return {lines, curWidth};
    }
};