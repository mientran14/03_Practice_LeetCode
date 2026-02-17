class Solution {
public:
    int totalMoney(int n) {
        int result = 0;

        for (int w = 0; w < n/7; w++) {
            result += (7 * w + 28);
        }

        for (int d = 0; d < n%7; d++) {
            result += (n/7 + 1 + d);
        }

        return result;
    }
};