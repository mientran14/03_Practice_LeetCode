class Solution {
public:
    int countDigits(int num) {
        int result = 0;
        int tmp = num;
        while (num > 0) {
            int digit = num % 10;
            if (tmp % digit == 0) result++;
            num /= 10;
        }
        return result;
    }
};
