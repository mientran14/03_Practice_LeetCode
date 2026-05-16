class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxcount = 0;
        int count0 = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) count0++;

            while (count0 > k) {
                if (nums[left] == 0) count0--;
                left++;
            }

            maxcount = max(maxcount, right - left + 1);
            right++;
        }

        return maxcount;
    }
};