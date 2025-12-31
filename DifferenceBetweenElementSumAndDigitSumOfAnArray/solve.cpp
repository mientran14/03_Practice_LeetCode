class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0, digitSum = 0;
        for (int n : nums) {
            elementSum += n;
            while (n > 0) {
                digitSum += n % 10;
                n /= 10;
            }
        }
        return abs(elementSum - digitSum);
    }
};
