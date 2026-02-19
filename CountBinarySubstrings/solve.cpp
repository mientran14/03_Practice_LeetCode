class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int prevGr = 0, curGr = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) curGr++;
            else {
                prevGr = curGr;
                curGr = 1;
            }
            if (prevGr >= curGr) result++;
        }

        return result;
    }
};