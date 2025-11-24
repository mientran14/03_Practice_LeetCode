class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int r = 0;
        vector<bool> result;

        for (int n : nums) {
            r = ((r << 1) + n) % 5;
            result.push_back(r == 0);
        }
        return result;
    }
};
