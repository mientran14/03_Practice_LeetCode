class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> answer0, answer1;

        for (int n : set1) {
            if (set2.find(n) == set2.end()) answer0.push_back(n);
        }

        for (int n : set2) {
            if (set1.find(n) == set1.end()) answer1.push_back(n);
        }

        return {answer0, answer1};
    }
};