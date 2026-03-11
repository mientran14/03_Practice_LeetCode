class Solution {
public:
    int bitwiseComplement(int n) {
        // if (n == 0) return 1;
        // int result = 0, power = 1;
        // while (n > 0) {
        //     int bit = n % 2 == 0 ? 1 : 0;
        //     result += bit * power;
        //     power *= 2;
        //     n /= 2;
        // }
        // return result;

        if (n == 0) return 1;
        int mask = 0, tmp = n;
        while (tmp > 0) {
            mask = (mask << 1) | 1;
            tmp >>= 1;
        }
        return n^mask;
    }
};