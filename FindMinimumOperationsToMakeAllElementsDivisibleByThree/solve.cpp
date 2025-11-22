class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;

        for (int x : nums) {
            int r = x % 3;

            // if (r == 1 || r == 2) {
            //     result++;
            // }

            if (r != 0) {
                result += min(r, 3 - r);
            }
        }
        return result;
    }
};
