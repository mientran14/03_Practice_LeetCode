class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // // sort(nums.rbegin(), nums.rend()); // lâu hơn chút vì reverse mapping
        // sort(nums.begin(), nums.end(), greater<int>());
        // for (int i = 0; i < nums.size() - 2; i++) {
        //     if (nums[i] < nums[i+1] + nums[i+2]) {
        //         return nums[i] + nums[i+1] + nums[i+2];
        //     }
        // }

        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            if (nums[i-2] + nums[i-1] > nums[i]) {
                return nums[i-2] + nums[i-1] + nums[i];
            }
        }

        return 0;
    }
};