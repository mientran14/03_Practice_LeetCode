class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int n : nums) {
            vector<int> digit;
            while (n > 0) {
                digit.push_back(n % 10);
                n /= 10;
            }
            reverse(digit.begin(), digit.end());
            for (int d : digit) {
                answer.push_back(d);
            }
        }
        return answer;
    }
};