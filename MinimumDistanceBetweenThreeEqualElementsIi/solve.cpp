class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int result = INT_MAX;
        unordered_map<int, vector<int>> idx;
        for(int i = 0; i < nums.size(); i++) idx[nums[i]].push_back(i);
        for(auto& [num, indices] : idx) {
            if(indices.size() < 3 ) continue;
            for(int i = 0; i < indices.size() - 2; i++) {
                int dist = abs(indices[i] - indices[i+1]) + abs(indices[i+1] - indices[i+2]) + abs(indices[i+2] - indices[i]);
                result = min(result, dist);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};