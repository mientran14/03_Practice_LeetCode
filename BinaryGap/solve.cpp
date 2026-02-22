class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        int prev = -1, curr = 0;
        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    result = max(result , curr - prev);
                }
                prev = curr;
            }
            n >>= 1;
            curr++;
        }
        return result;
    }
};