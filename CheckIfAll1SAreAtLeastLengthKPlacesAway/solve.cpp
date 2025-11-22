class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int place = -1;
        for (int i =0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (place != -1 && i-place-1 < k) {
                    return false;
                }
                place = i;
            }
        }
        return true;
    }
};
