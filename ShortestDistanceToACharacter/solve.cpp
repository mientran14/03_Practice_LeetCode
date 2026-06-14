class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> result(n);

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) pos.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int minDis = n;
            for (int p : pos) {
                minDis = min(minDis, abs(i - p));
            }
            result[i] = minDis;
        }

        return result;
    }
};