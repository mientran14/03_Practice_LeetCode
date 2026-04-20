class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        if (maxVal - minVal <= 2*k) return 0;
        else return maxVal - minVal - 2*k;
    }
};