class Solution {
public:
    bool checkString(string s) {
        bool flag_b = false;
        for(char c : s) {
            if(c == 'b') flag_b = true;
            else if (flag_b && c == 'a') return false;
        }
        return true;
    }
};