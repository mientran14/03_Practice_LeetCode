class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndx = 0;
        int oddIndx = 1;
        while (evenIndx < nums.size() && oddIndx < nums.size()) {
            if (nums[evenIndx] % 2 == 0) evenIndx += 2;
            else if (nums[oddIndx] % 2 != 0) oddIndx += 2;
            else {
                swap(nums[evenIndx], nums[oddIndx]);
                evenIndx += 2;
                oddIndx += 2;
            }
        }
        return nums;
    }
};
