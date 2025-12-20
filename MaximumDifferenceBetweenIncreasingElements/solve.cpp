class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minnums = INT_MAX, result = -1;
        for (int n : nums) {
            if (n > minnums) {
                result = max(result, n - minnums);
            }
            minnums = min(minnums, n);
        }
        return result;
    }
};