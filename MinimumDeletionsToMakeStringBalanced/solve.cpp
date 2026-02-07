class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int result = 0;

        for (char c : s) {
            if (c == 'b') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    result++;
                } else {
                    // Nothing to do, keep a
                }
            }
        }

        return result;
    }
};
