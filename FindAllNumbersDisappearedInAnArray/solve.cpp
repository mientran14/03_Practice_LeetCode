class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // set<int> tmpnums(nums.begin(), nums.end());          // O(nlogn)

        // O(n) but 35ms is still too slow!!!!!!!!!!!!!!!!
        unordered_set<int> tmpnums(nums.begin(), nums.end()); 
        vector<int> result;
        for(int i = 1; i <= nums.size(); i++) {
            if(tmpnums.find(i) == tmpnums.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};
