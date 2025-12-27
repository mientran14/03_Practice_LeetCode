class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal, maxIndxVal;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndxVal = i; 
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (maxVal < nums[i]*2 && maxIndxVal != i) return -1;
        }
        return maxIndxVal;
    }
};
