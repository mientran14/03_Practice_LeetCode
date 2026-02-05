class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int steps = i + nums[i];
            int newIdx = (steps % n + n) % n;
            result[i] = nums[newIdx];
        }
        return result;
    }
};