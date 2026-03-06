class Solution {
public:
    bool checkOnesSegment(string s) {
        // int count01 = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) count01++;
        //     if (count01 > 1) return false;
        // }
        // return true;
        return s.find("01") == string::npos;
    }
};