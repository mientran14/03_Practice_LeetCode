class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool incrFlg = true;
        bool decrFlg = true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) incrFlg = false;
            if (nums[i] < nums[i + 1]) decrFlg = false;
        }

        return incrFlg || decrFlg;
    }
};