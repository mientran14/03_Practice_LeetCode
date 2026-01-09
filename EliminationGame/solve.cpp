class Solution {
public:
    int lastRemaining(int n) {
        int result = 1;
        int step = 1;
        bool l2r = true;

        while (n > 1) {
            if (l2r || n % 2 == 1) {
                result += step;
            }
            n /= 2;
            step *= 2;
            l2r = !l2r;
        }
        return result;
    }
};
