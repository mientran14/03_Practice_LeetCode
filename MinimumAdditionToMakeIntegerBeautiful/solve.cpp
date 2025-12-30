class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        // // LTE.................
        // long long x = 0;
        // while (true) {
        //     long long sumDigit = 0;
        //     long long tmp = n + x;
        //     while (tmp > 0) {
        //         sumDigit += tmp % 10;
        //         tmp /= 10;
        //     }

        //     if (sumDigit <= target) {
        //         return x;
        //     }
        //     x++;
        // }


        long long x = 0;
        long long mult = 1;
        while (true) {
            long long sumDigit = 0;
            long long tmp = n + x;
            while (tmp > 0) {
                sumDigit += tmp % 10;
                tmp /= 10;
            }

            if (sumDigit <= target) break;

            long long remaind = (n + x) % mult;
            x += mult - remaind;
            mult *= 10;
        }
        return x;
    }
};