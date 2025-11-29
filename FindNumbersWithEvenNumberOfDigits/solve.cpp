class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int n : nums) {
            string s = to_string(n);
            if (s.size()%2 == 0) {
                result++;
            }
        }
        return result;
    }
};
