class Solution {
public:
    int countAsterisks(string s) {
        int countBar = 0;
        int countAsterisk = 0;
        for (char c : s) {
            if (c == '|') countBar++;
            else if (c == '*') {
                if (countBar % 2 == 0) countAsterisk++;
            }
        }
        return countAsterisk;
    }
};