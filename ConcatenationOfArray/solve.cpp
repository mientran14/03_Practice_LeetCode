class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> ans(n*2);
        // for (int i = 0; i < n; i++) {
        //     ans[i] = nums[i];
        //     ans[i+n] = nums[i];
        // }
        // return ans;

        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};