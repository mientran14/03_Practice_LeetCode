class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j;
        j=1;
        for (i=1; i< nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
