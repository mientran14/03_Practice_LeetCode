class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int indexNon0 = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != 0) {
        //         nums[indexNon0] = nums[i];
        //         indexNon0++;
        //     }
        // }
        // for (int i = indexNon0; i < nums.size(); i++) {
        //     nums[i] = 0;
        // }

        // int left = 0;
        // for (int right = 0; right < nums.size(); right++) {
        //     if (nums[right] != 0) {
        //         int tmp = nums[left];
        //         nums[left] = nums[right];
        //         nums[right] = tmp;
        //         left++;
        //     }
        // }

        int indexNon0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) swap(nums[indexNon0++], nums[i]);
        }
    }
};