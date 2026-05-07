class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !vowel.count(s[left])) {
                left++;
            }
            while (left < right && !vowel.count(s[right])) {
                right--;
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};