class Solution {
public:
    string smallestSubsequence(string s) {
        if (s.empty()) return "";

        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int pos = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[pos]) pos = i;
            count[s[i] - 'a']--;
            
            if (count[s[i] - 'a'] == 0) break;
        }

        string suffix = s.substr(pos + 1);
        erase(suffix, s[pos]);

        return s[pos] + smallestSubsequence(suffix);
    }
};