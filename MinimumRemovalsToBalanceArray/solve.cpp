class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), result = n;
        sort(nums.begin(), nums.end());

        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && (long long)nums[right] <= (long long)nums[left] * k) {
                right++;
            }
            result = min(result, n - (right - left));
        }

        return result;
    }
};