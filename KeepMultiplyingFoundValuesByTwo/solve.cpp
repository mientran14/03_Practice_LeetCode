class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // unordered_set<int> tmp(nums.begin(), nums.end());
        // while (tmp.find(original) != tmp.end()) {
        //     original *= 2;
        // }
        // return original;

        bool found = true;
        while (found) {
            found = false;
            for (int n : nums) {
                if (n == original) {
                    found = true;
                    break;
                }
            }
            if (found) {
                original *= 2;
            }
        }
        return original;
    }
};