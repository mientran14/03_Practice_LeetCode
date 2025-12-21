class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return(s == t);

        if (s.size() != t.size()) return false;
        unordered_map<char, int> countChar;
        for (int i = 0; i < s.size(); i++) {
            countChar[s[i]]++;
            countChar[t[i]]--;
        }
        for (auto c : countChar)
            if (c.second) return false;
        return true;
    }
};