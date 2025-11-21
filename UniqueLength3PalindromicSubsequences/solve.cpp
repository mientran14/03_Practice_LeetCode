class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        unordered_map<char, pair<int, int>> prefix;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (prefix.find(c) == prefix.end()) {
                prefix[c] = {i, i};
            } else {
                prefix[c].second = i;
            }
        }

        for (auto [c, len] : prefix) {
            int left = len.first;
            int right = len.second;

            if (left < right) {
                unordered_set<char> uniqueChars;
                for (int i = left+1; i < right; i++) {
                    uniqueChars.insert(s[i]);
                }
                count += uniqueChars.size();
            }
        }
        return count;
    }
};
