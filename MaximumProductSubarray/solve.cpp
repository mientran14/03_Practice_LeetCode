class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());
        int currMax = 1, currMin = 1;

        for (int cur : nums) {
            if (cur == 0) {
                currMax = 1;
                currMin = 1;
                continue;
            }
            
            int tmp = currMax * cur;
            currMax = max({cur * currMax, cur * currMin, cur});
            currMin = min({tmp, cur * currMin, cur});
            
            result = max(result, currMax);
        }

        return result;
    }
};