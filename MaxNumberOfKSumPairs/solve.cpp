class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int n : nums) {
            int remainpair = k - n;
            if (freq[remainpair] > 0) {
                count++;
                freq[remainpair]--;
            } 
            else freq[n]++;
        }

        return count;
    }
};