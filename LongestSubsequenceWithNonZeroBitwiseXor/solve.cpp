class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int arrayXor = 0;
        int zeroCount = 0;

        for (int n : nums) {
            arrayXor ^= n;
            if (n == 0) zeroCount++;
        }

        if (arrayXor != 0) return nums.size();
        
        return (zeroCount == nums.size()) ? 0 : nums.size() - 1;
    }
};