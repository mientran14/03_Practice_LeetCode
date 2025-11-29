class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // int result; 
        // int sum = 0;
        // for (int n : nums) {
        //     sum += n;
        //     result = sum % k ;
        // }
        // return result;

        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};
