class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        auto isPrime = [](int n) {
            if (n < 2) return false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) return false;
            }
            return true;
        };

        auto countSetBits = [](int n) {
            int count = 0;
            while (n > 0) {
                count += (n & 1);
                n >>= 1;
            }
            return count;
        };

        int result = 0;
        for (int i = left; i <= right; i++) {
            int setBits = countSetBits(i);
            if (isPrime(setBits)) result++;
        }

        return result;
    }
};