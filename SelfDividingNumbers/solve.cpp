class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int n = left; n <= right; n++) {
            int tmp = n;
            bool isSelfDivi = true;
            while (tmp > 0) {
                int digit = tmp % 10;
                if (digit == 0 || n%digit != 0) {
                    isSelfDivi = false;
                    break;
                }
                tmp /= 10;
            }
            if (isSelfDivi) result.push_back(n);
        }
        return result;
    }
};
