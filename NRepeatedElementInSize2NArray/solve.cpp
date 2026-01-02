class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // // 23ms
        // unordered_map<int, int> count;
        // for (int n : nums) {
        //     count[n]++;
        //     if(count[n] == nums.size()/2) return n;
        // }
        // return -1;

        for (int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) return nums[j];
            }
        }
        return 0;
    }
};