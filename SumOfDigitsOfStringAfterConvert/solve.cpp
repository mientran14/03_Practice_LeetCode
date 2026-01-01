class Solution {
public:
    int getLucky(string s, int k) {
        int sumDigit = 0;
        for (char c : s) {
            int value = c - 'a' + 1;
            while (value > 0) {
                sumDigit += value % 10;
                value /= 10;
            }
        }
        while (k > 1) {
            int newsumDigit = 0;
            while (sumDigit > 0) {
                newsumDigit += sumDigit % 10;
                sumDigit /= 10;
            }
            sumDigit = newsumDigit;
            k--;
        }
        return sumDigit;
    }
};
