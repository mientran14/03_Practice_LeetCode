class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0, sign = 1;
        string num = to_string(n);
        for (char c : num) {
            int digit = c - '0';
            sum += sign * digit;
            sign = -sign;
        }
        return sum;
    }
};
