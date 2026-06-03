class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) diff.push_back(i);
        }
        
        if (diff.size() == 0) {
            unordered_map<char, int> freq;
            for (char c : s) freq[c]++;
            for (auto f : freq) {
                if (f.second > 1) return true;
            }
            return false;
        }
        
        if (diff.size() == 2) {
            int i = diff[0];
            int j = diff[1];
            return s[i] == goal[j] && s[j] == goal[i];
        }
        
        return false;
    }
};