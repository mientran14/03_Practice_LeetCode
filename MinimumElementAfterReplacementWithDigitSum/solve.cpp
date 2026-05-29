class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (int n : nums) {
            int digitSum = 0;
            while (n > 0) {
                digitSum += n % 10;
                n /= 10;
            }
            result = min(result, digitSum);
        }
        return result;
    }
};