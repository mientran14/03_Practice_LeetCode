class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int maxK = -1;
        for (int n : nums) {
            if (n > 0) {
                if (binary_search(nums.begin(), nums.end(), -n)) {
                    maxK = max(maxK, n);
                }
            }
        }
        return maxK;
    }
};
