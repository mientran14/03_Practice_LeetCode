class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> numssorted = nums;
        sort(numssorted.rbegin(), numssorted.rend());
        vector<int> elementsK(numssorted.begin(), numssorted.begin() + k);

        vector<int> result;
        for (int n : nums) {
            auto it = find(elementsK.begin(), elementsK.end(), n);
            if (it != elementsK.end()) {
                result.push_back(n);
                elementsK.erase(it);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
