class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        // int result = 0;
        // for (int i = 0; i < hours.size(); i++) {
        //     for (int j = i+1; j < hours.size(); j++) {
        //         if (i != j && (hours[i] + hours[j]) % 24 == 0) result++;
        //     }
        // }
        // return result;

        int result = 0;
        unordered_map<int, int> freq;
        for (int h : hours) {
            int complement = (24-(h%24) + 24) % 24;
            result += freq[complement];
            int remainder = (h%24 + 24) % 24;
            freq[remainder]++;
        }
        return result;
    }
};