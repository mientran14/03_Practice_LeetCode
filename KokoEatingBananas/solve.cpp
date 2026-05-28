class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int result = right;
        while(left <= right) {
            int mid = left + (right-left)/2;
            long long hour = 0;
            for (int p : piles) {
                hour += (p + mid - 1)/mid;
            }
            if (hour <= h) {
                result = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return result;
    }
};