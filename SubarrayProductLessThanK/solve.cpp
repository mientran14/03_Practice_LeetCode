class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // int result = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int product = 1;
        //     for (int j = i; j < nums.size(); j++) {
        //         product *= nums[j];
        //         if (product < k) {
        //             result++;
        //         }
        //         else break;
        //     }
        // }
        // return result;

        // Sliding Window:
        if (k <= 1) return 0;
        int product = 1;
        int left = 0;
        int result = 0;
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            result += (right - left + 1);
        }
        return result;
    }
};
