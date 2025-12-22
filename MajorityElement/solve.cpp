class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // Time: O(nlogn), Spaces: O(1)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];

        // // Time: O(n), Spaces: O(n)
        // unordered_map<int, int> countN;
        // for (int n : nums) {
        //     countN[n]++;
        //     if (countN[n] > nums.size()/2) return n;
        // }
        // return -1;

        // Time: O(n), Spaces: O(1)
        int element = 0;
        int count = 0;
        for (int n : nums) {
            if (count == 0) element = n;
            if (n == element) count += 1;
            else count -= 1;
        }
        return element;
    }
};