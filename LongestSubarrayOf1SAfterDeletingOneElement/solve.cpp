class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int maxcount = 0;
        int count0 = 0;
        
        while (right < nums.size()) {
            if (nums[right] == 0) count0++;

            while (count0 > 1) {
                if (nums[left] == 0) count0--;
                left++;
            }

            maxcount = max(maxcount, right - left);
            right++;
        }

        return maxcount;
    }
};