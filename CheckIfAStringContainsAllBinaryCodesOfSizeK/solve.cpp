class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string> subK;
        for (int i = 0; i <= s.size()-k; i++) {
            subK.insert(s.substr(i,k));
        }
        return subK.size() == (1<<k);
    }
};