class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                int dist = abs(i - start);
                result = min(result, dist);
            }
        }
        return result;
    }
};