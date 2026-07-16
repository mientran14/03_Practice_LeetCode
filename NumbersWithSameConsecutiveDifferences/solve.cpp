class Solution {
public:
    void dfs (int n, int k, int curNum, int curLen, vector<int>& result) {
        if(curLen == n) {
            result.push_back(curNum);
            return;
        }

        int lastDigit = curNum % 10;

        if (lastDigit + k < 10) {
            dfs(n, k, curNum*10 + (lastDigit + k), curLen + 1, result);
        }

        if (lastDigit - k >= 0 && k > 0) {
            dfs(n, k, curNum*10 + (lastDigit - k), curLen + 1, result);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for(int i = 1; i <= 9; i++) {
            dfs(n, k, i, 1, result);
        }
        return result;
    }
};