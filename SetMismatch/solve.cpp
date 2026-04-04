class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> freq;
        int dup = -1, miss = -1;

        for (int n : nums) {
            freq[n]++;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if(freq[i] == 2) dup = i;
            else if (freq[i] == 0) miss = i;
        }
        
        return {dup, miss};
    }
};