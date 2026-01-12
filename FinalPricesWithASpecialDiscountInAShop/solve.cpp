class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                prefix[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (prefix[i] != -1) {
                result[i] = prices[i] - prices[prefix[i]];
            } else {
                result[i] = prices[i];
            }
        }

        return result;
    }
};
