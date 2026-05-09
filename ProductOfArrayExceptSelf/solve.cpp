class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // refer: https://leetcode.com/problems/construct-product-matrix/description/

        vector<int> answer(nums.size(), 1);

        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};