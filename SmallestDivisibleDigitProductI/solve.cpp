class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++) {
            int k = i;
            int x = 1;
            while (k > 0) {
                x *= (k % 10);
                k /= 10;
            }
            if (x % t == 0) return i;
        }
        return n;
    }
};