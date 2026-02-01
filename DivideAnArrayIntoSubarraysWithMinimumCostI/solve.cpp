class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result = INT_MAX;
        for (int i = 1; i < nums.size()-1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int calcost = nums[0] + nums[i] + nums[j];
                result = min(result, calcost);
            }
        }
        return result;
    }
};