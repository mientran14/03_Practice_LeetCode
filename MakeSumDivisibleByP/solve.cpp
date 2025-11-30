class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long sum = 0;
        for (int n : nums) {
            sum += n;
        }
        int r = sum % p;
        if (r == 0) return 0;

        // // Time Limit Exceeded
        // int minLen = nums.size();
        // for (int i = 0; i < nums.size(); i++) {
        //     long subSum = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         subSum += nums[j];
        //         if (subSum % p == r) {
        //             minLen = min(minLen, j - i + 1);
        //         }
        //     }
        // }
        // return minLen == nums.size() ? -1 : minLen;

        unordered_map<int,int> modMap;
        modMap[0] = -1;
        long currSum = 0;
        int minLen = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int currMod = currSum % p;
            int targetMod = (currMod - r + p) % p;

            if (modMap.find(targetMod) != modMap.end()) {
                minLen = min(minLen, i-modMap[targetMod]);
            }
            modMap[currMod] = i;
        }
        return minLen == nums.size() ? -1 : minLen;
    }
};
