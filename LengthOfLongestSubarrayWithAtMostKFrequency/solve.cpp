class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int result = 0;

        // Sliding Window
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};