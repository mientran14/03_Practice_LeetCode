class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int sumDigit = 0;
            while (num > 0) {
                sumDigit += num % 10;
                num /= 10;
            }
            num = sumDigit;
        }
        return num;
    }
};
