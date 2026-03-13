class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);

        for (int num : arr) {
            int remainder = ((num % k) + k) % k; // Đảm bảo remainder >= 0
            freq[remainder]++;
        }

        for (int r = 0; r < k; r++) {
            if (r == 0) {
                if (freq[r] % 2 != 0) return false;
            } 
            else {
                if (freq[r] != freq[k - r]) return false;
            }
        }
        return true;
    }
};