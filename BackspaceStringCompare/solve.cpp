class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stackS, stackT;

        for (char c : s) {
            if (c == '#') {
                if (!stackS.empty()) stackS.pop();
            } 
            else stackS.push(c);
        }

        for (char c : t) {
            if (c == '#') {
                if (!stackT.empty()) stackT.pop();
            } 
            else stackT.push(c);
        }

        return stackS == stackT;
    }
};