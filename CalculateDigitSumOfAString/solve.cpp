class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string newS = "";
            for(int i = 0; i < s.size(); i += k) {
                int sumDigit = 0;
                for(int j = i; j < s.size() && j < i+k; j++) {
                    sumDigit += s[j] - '0';
                }
                newS += to_string(sumDigit);
            }
            s = newS;
        }
        return s;
    }
};
