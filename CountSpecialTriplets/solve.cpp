class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        if (nums.size() < 3) return 0;

        int maxValue = 0;
        for (int val : nums) if (val > maxValue) maxValue = val;

        int sz = maxValue*2 + 1; 
        vector<long long> countLeft(sz, 0), countRight(sz, 0);

        for (int v : nums) countRight[v]++;

        long long result = 0;
        for (int j = 0; j < nums.size(); ++j) {

            countRight[nums[j]]--;
            
            int target = nums[j] * 2;
            if (target < sz) {
                result += (countLeft[target] * countRight[target]) % MOD;
            }

            countLeft[nums[j]]++;
        }
        return result % MOD;
    }
};