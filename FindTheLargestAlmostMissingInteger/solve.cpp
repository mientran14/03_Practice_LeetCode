class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> countSub;
        
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> sub(nums.begin() + i, nums.begin() + i + k);
            for (int s : sub) countSub[s]++;
        }
        
        int result = -1;
        for (auto [s, freq] : countSub) {
            if (freq == 1) result = max(result, s);
        }
        return result;
    }
};