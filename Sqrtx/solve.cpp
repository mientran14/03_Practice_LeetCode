class Solution {
public:
    int mySqrt(int x) {
        int L = 0, R = x, result = 0;
        while ( L <= R) {
            long long mid = L + (R-L)/2;
            long long square = mid*mid;

            if(square == x) {
            return mid;
            }
            else if (square < x) {
                result = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        return result;
    }
};
