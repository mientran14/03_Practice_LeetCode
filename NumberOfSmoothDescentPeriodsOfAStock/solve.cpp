class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long numperiod = 0;
        long long subperiod = 1; // 1 ngày đơn lẻ cũng là hợp lệ.
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i-1] - 1) {
                subperiod++;
            }
            else subperiod = 1;

            numperiod += subperiod;
        }
        return numperiod + 1;
    }
};
