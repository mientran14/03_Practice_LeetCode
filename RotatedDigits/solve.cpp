class Solution {
public:
    int rotatedDigits(int n) {
        auto isGood = [](int g) -> bool {
            bool flag = false;
            while (g > 0) {
                int digit = g % 10;
                // digit == 0 || digit == 1 || digit == 8   ->  rotate to themselves -> No change
                if (digit == 3 || digit == 4 || digit == 7) return false;
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) flag = true;
                g /= 10;
            }
            return flag;
        };
        
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) count++;
        }
        return count;
    }
};