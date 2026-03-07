class Solution {
public:
    bool isPowerOfThree(int n) {
        // // #1
        // if (n <= 0) return false;
        // while (n % 3 == 0) n /= 3;
        // return n == 1;

        // // #2
        if (n <= 0) return false;
        if (n == 1) return true;
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};