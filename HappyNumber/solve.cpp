class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tmp;
        while(n != 1 && tmp.find(n) == tmp.end()) {
            tmp.insert(n);
            int sumSquare = 0;
            while (n > 0) {
                int digit = n % 10;
                sumSquare += digit * digit;
                n /= 10;
            }
            n = sumSquare;
        }
        return n == 1;
    }
};
