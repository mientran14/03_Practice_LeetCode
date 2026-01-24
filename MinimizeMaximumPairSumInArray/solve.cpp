class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            result = max(result, nums[left] + nums[right]);
            left++; 
            right--;
        }

        return result;
    }
};