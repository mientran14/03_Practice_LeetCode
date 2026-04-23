class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // TLE 1062/1068 testcases passed
        // Need to fix
        int n = nums.size();
        vector<long long> result(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    result[i] += abs(i - j);
                }
            }
        }
        return result;
    }
};