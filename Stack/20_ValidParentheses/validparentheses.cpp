class Solution {
public:
    bool isValid(string s) {
    unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    stack<char> st;
    char topstack;

    for (char c : s) {
        if (brackets.count(c)) {
            if (st.empty()) {
                topstack = ' ';
            }
            else {
                topstack = st.top();
            }

            if (topstack == brackets[c]) {
                st.pop(); 
            } else {
                return false; 
            }
        } 
        else {
            st.push(c);
        }
    }
    return st.empty();
    }
};