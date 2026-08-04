class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> missing;
        for (int i = 0; i < nums.size()-1; i++) {
            for (int cur = nums[i] + 1; cur < nums[i+1]; cur++) {
                missing.push_back(cur);
            }
        }
        return missing;
    }
};