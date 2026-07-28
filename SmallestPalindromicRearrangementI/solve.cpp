class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; ++i) {
            char ch = 'a' + i;
            left.append(count[i] / 2, ch);
            if (count[i] % 2 != 0) mid = ch;
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};