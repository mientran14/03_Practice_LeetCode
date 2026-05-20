class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001, 0);  // -1000 <= arr[i] <= 1000

        for (int num : arr) {
            freq[num + 1000]++;
        }

        unordered_set<int> seen;
        for (int count : freq) {
            if (count > 0) {
                if (seen.find(count) != seen.end()) return false;
                seen.insert(count);
            }
        }

        return true;
    }
};