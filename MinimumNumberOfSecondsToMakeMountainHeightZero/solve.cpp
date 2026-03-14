class Solution {
public:
    long long maxHeightReduced(long long Tmax, int t) {
        long long maxHeight = 0;
        long long left = 0, right = 1e6;                // 1 <= mountainHeight <= 105

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long reqTime = t * (mid*(mid+1)/2);    // = t * (1+2+...+mid)

            if (reqTime <= Tmax) {
                maxHeight = mid;
                left = mid + 1;
            } 
            else right = mid - 1;
        }
        return maxHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;
        long long result = right;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long reduced = 0;

            for (int t : workerTimes) {
                reduced += maxHeightReduced(mid, t);
                if (reduced >= mountainHeight) {
                    result = mid;
                    right = mid - 1;
                    break;
                }
            }
            
            if (reduced < mountainHeight) left = mid + 1;
        }
        return result;
    }
};