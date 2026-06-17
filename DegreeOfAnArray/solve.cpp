class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;
        int degree = 0, minLen = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (first.find(nums[i]) == first.end()) first[nums[i]] = i;
            last[nums[i]] = i;
            degree = max(degree, ++freq[nums[i]]);
        }

        for (auto& [num, count] : freq) {
            if (count == degree) {
                minLen = min(minLen, last[num] - first[num] + 1);
            }
        }

        return minLen;
    }
};