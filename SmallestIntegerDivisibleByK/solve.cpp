class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r = 0;
        for (int len=1; len<=k; len++) {
            r = (r*10 + 1) % k;
            if (r==0) return len;
        }
        return -1;
    }
};
