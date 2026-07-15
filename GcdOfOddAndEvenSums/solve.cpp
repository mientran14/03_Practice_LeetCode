class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // sumOdd = n^2
        // sumEven = n(n + 1)
        // GCD(sumOdd,sumEven) = GCD(n^2, n(n + 1)) = n*GCD(n, n + 1) = n*1 = n
        return n;
    }
};