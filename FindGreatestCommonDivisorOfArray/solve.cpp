class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = 0;
        for (int n : nums) {
            mn = min(mn, n);
            mx = max(mx, n);
        }
        while (mx != 0) {
            int tmp = mx;
            mx = mn % mx;
            mn = tmp;
        }
        return mn;
    }
};