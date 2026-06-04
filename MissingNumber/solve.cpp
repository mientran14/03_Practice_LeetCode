class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long expectSum = nums.size() * (nums.size() + 1) / 2;
        long long actualSum = 0;
        
        for (int n : nums) {
            actualSum += n;
        }
        
        return expectSum - actualSum;
    }
};