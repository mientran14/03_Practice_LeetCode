class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int minSum = INT_MAX; 
        for (int j = 1; j < nums.size() - 1; j++) {
            int leftMin = INT_MAX;  
            int rightMin = INT_MAX; 

            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    leftMin = min(leftMin, nums[i]);
                }
            }

            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[k] < nums[j]) {
                    rightMin = min(rightMin, nums[k]);
                }
            }

            if (leftMin != INT_MAX && rightMin != INT_MAX) {
                minSum = min(minSum, leftMin + nums[j] + rightMin);
            }
        }
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
