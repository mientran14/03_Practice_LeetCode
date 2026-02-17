class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            // string s_new = "";
            // for(int i = 0; i < s.size()-1; i++) {
            //     int digit1 = s[i] - '0';
            //     int digit2 = s[i+1] - '0';
            //     int digitnew = (digit1+digit2)%10;
            //     s_new += to_string(digitnew);
            // }
            // s = s_new;

            for(int i = 0; i < s.size()-1; i++) {
                s[i] = (s[i]-'0' + s[i+1]-'0') % 10 + '0';
            }
            s.pop_back();
        }
        return s[0] == s[1];
    }
};