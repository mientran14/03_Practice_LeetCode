class Solution {
public:
    int climbStairs(int n) {
        // // top‑down -> (O(2^n)) -> LTE
        // if (n == 0 || n == 1) {
        //     return 1;
        // }
        // return climbStairs(n-1) + climbStairs(n-2);

        // bottom‑up
        int a = 0;
        int b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};