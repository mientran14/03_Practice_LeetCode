class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0, curSum = 0;

        for (int i = 0; i < k; i++) {
            curSum += nums[i];
        }
        maxSum = curSum;

        // Sliding Window
        for (int i = k; i < nums.size(); i++) {
            curSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, curSum);
        }

        return maxSum/k;
    }
};