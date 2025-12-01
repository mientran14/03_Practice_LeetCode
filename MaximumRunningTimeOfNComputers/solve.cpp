class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sumPin = 0;
        for (int b : batteries) sumPin +=b;

        long long left=0, right=sumPin/n, result=0;
        while (left <= right) {
            long long mid = (left+right)/2;
            long long needpin = n*mid; 
            long long avaipin = 0;

            for (int b : batteries) {
                avaipin += min((long long)b, mid);
            }

            if (avaipin >= needpin) {
                result = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
};
