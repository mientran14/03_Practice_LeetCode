class Solution {
public:
    bool rotateString(string s, string goal) {
        // if (s.size() != goal.size()) return false;
        // for (int i = 0; i < s.size(); i++) {
        //     char firstChar = s[0];
        //     s.erase(s.begin());
        //     s.push_back(firstChar);
        //     if (s == goal) return true;
        // }
        // return false;

        if(s.size() != goal.size()) return false;
        string doubleS = s + s;
        return doubleS.find(goal) != string::npos;
    }
};