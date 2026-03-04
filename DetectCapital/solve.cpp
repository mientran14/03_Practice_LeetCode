class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for (char c : word) {
            if (isupper(c)) capitalCount++;
        }
        return (capitalCount == word.size()) || (capitalCount == 0) || (capitalCount == 1 && isupper(word[0]));
    }
};