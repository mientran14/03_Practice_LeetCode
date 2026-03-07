class Solution {
public:
    bool isPowerOfFour(int n) {
        // // #1
        // if (n <= 0) return false;
        // while (n % 4 == 0) n /= 4;
        // return n == 1;

        // // #2
        // if (n <= 0) return false;
        // if (n == 1) return true;
        // return n % 4 == 0 && isPowerOfFour(n / 4);

        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};