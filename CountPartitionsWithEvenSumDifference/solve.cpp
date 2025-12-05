class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;

        int sumL = 0;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            sumL += nums[i];
            int sumR = sum - sumL;
            if ((sumL - sumR) % 2 == 0) count++;
        }
        return count; 
    }
};