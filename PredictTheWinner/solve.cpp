class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);                           // diff [i, j]

        // nums[i] -> nums[i+1...j]
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                int pickLeft = nums[i] - dp[j];         // Opt1: pick the first
                int pickRight = nums[j] - dp[j-1];      // Opt2: pick the last
                dp[j] = max(pickLeft, pickRight);
            }
        }
        
        return dp[n - 1] >= 0;
    }
};