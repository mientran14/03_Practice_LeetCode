class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int result = INT_MAX;
        int maxScore = 0;
        for (int i = 0; i <= divisors.size() - 1; i++) {
            int score = 0;
            for (int n : nums) {
                if (n % divisors[i] == 0) {
                    score++;
                }
                if (score > maxScore) {
                    maxScore = score;
                    result = divisors[i];
                }
                else if (score == maxScore) {
                    result = min(result, divisors[i]);
                }
            }
        }
        return result;
    }
};