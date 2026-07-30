class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int left = nums[0];
        
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) continue; 
            
            if ((nums[i] > left && nums[i] > nums[i + 1]) ||  (nums[i] < left && nums[i] < nums[i + 1])) {
                count++;
            }
            
            left = nums[i];
        }
        
        return count;
    }
};