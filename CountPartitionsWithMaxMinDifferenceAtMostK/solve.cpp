class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        // LTE ????????
        const int MOD = 1e9 + 7;
        unordered_map<int, long> memo;
        function<long(int)> F = [&](int i) -> long {
            if (i == nums.size()) return 1;
            if (memo.count(i)) return memo[i];

            long ways = 0;
            long cur_min = LONG_MAX;
            long cur_max = LONG_MIN;
            for (int j = i; j < nums.size(); j++) {
                cur_min = min(cur_min, (long)nums[j]);
                cur_max = max(cur_max, (long)nums[j]);

                if (cur_max - cur_min > k) break;
                
                ways += F(j + 1);
            }
            return memo[i] = ways % MOD;
        };
        return F(0);
    }
};