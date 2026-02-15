class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int maxFreq = 0, result = 0;
        for (int n : nums) {
            freq[n]++;
            maxFreq = max(maxFreq, freq[n]);
        } 
        for (int f : freq) {
            if (f == maxFreq) result += f;
        }
        return result;
    }
};