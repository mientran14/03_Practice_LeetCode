class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums;

        // vector<int> prefix(nums.size());
        // prefix[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++) {
        //     prefix[i] = prefix[i-1] + nums[i];
        // }
        // return prefix;
    }
};