class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;

        // // Array
        // vector<int> count(nums.size(), 0);
        // for (int n : nums) count[n]++;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (count[i] == 2) result.push_back(i);
        // }

        // // Hash set
        // unordered_set<int> seen;
        // for (int n : nums) {
        //     if (seen.count(n)) result.push_back(n);
        //     else seen.insert(n);
        // }

        // Sort
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                result.push_back(nums[i]);
                i++;
            }
        }

        return result;
    }
};