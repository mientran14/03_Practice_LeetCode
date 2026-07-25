class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {       
        unordered_set<int> xor2;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                xor2.insert(nums[i] ^ nums[j]);
            }
        }
        
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        
        unordered_set<int> xor2w3;
        for (int x : xor2) {
            for (int u : uniqueNums) {
                xor2w3.insert(x ^ u);
            }
        }

        return xor2w3.size();
    }
};