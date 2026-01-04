class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int n : nums) {
            vector<int> divisors;
            for (int i = 1; i*i <= n; i++) {
                if (n % i == 0) {
                    divisors.push_back(i);
                    if (i != n/i) {
                        divisors.push_back(n/i);
                    }
                }
            }
            if (divisors.size() == 4) {
                result += accumulate(divisors.begin(), divisors.end(), 0);
            }
        }
        return result;
    }
};
