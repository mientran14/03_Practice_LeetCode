class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;
        int ans = 1;
        
        for (auto& [x, count] : freq) {
            if (x == 1) {
                ans = max(ans, count - (count % 2 == 0));
                continue;
            }
            
            long long curr = x;
            int len = 0;
            
            while (freq.count(curr) && freq[curr] >= 2) {
                len += 2;
                curr *= curr;
            }
            
            if (freq.count(curr)) len += 1; 
            else len -= 1; 

            ans = max(ans, len);
        }
        
        return ans;
    }
};