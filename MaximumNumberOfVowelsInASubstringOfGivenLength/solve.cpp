class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int maxCount = 0, curCount = 0;

        for (int i = 0; i < k; i++) {
            if (vowel.count(s[i])) curCount++;
        }
        maxCount = curCount;

        // Sliding Window
        for (int i = k; i < s.size(); i++) {
            if (vowel.count(s[i - k])) curCount--;
            if (vowel.count(s[i])) curCount++;
            maxCount = max(maxCount, curCount);
        }

        return maxCount;
    }
};
