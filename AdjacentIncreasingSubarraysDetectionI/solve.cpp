class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // // Wrong
        // int countIncr = 0;
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     if(nums[i] < nums[i+1]) {
        //         countIncr++;
        //         if(countIncr >= 2*(k - 1)) {
        //             return true;
        //         }
        //     }
        //     else countIncr = 0;
        // }
        // return false;

        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        for (int i = k; i < nums.size(); i++) {
            if (dp[i] >= k && dp[i - k] >= k) {
                return true;
            }
        }
        return false;
    }
};