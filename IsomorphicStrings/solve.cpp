class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> s2t, t2s;

        for (int i = 0; i < s.size(); i++) {
            char cs = s[i], ct = t[i];

            if (s2t.count(cs) && s2t[cs] != ct) return false;
            if (t2s.count(ct) && t2s[ct] != cs) return false;

            s2t[cs] = ct;
            t2s[ct] = cs;
        }

        return true;
    }
};