class Solution {
public:
    bool judgeCircle(string moves) {
        // unordered_map <char, int> count;
        // for (char m : moves) {
        //     count[m]++;
        // }
        // return count['U'] == count['D'] && count['L'] == count['R'];

        int x = 0, y = 0;
        for (char m : moves) {
            if (m == 'R') x++;
            else if (m == 'L') x--;
            else if (m == 'U') y++;
            else if (m == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};