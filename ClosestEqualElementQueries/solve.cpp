class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // Need to improve
        // TLE 612/614 testcases passed
        vector<int> result;
        int n = nums.size();
        unordered_map<int, vector<int>> idxmap;

        for (int i = 0; i < n; i++) idxmap[nums[i]].push_back(i);
        
        for (int quer : queries) {
            int minDist = INT_MAX;
            int val = nums[quer];
            const vector<int>& tmp = idxmap[val];

            if (tmp.size() == 1) {
                result.push_back(-1);
                continue;
            }
            
            for (int j : tmp) {
                if (j != quer) {
                    minDist = min(minDist, min((j - quer + n) % n, (quer - j + n) % n));
                }
            }

            result.push_back(minDist);
        }

        return result;
    }
};