class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;

        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool sign = (dividend<0) ^ (divisor<0);
        long absDividend = abs((long)dividend);
        long absDivisor = abs((long)divisor);
        
        while (absDividend >= absDivisor) {
            long tmp = absDivisor;
            int multi = 1;
            while (absDividend >= (tmp << 1)) {
                tmp <<= 1;
                multi <<= 1;
            }
            absDividend -= tmp;
            quotient += multi;
        }

        return sign ? -quotient : quotient;
    }
};
