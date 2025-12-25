class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for (int n : nums) {
            if (n%2 == 0 && n%3 == 0) {
                count++;
                sum += n;
            }
        }
        if (count == 0) return 0;

        return sum/count;
    }
};