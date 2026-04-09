class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 2pointer
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();

        // dp... Need to improve
    }
};