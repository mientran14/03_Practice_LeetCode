class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int result = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (i%3 != 2) result += cost[i]; // i%3 == 2 la vien dc free
        }
        return result;
    }
};