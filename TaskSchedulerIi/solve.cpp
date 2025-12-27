class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> preDay;
        long long result = 0;

        for (int t : tasks) {
            if (preDay.find(t) != preDay.end()) {
                if (result < preDay[t] + space) {
                    result = preDay[t] + space;
                }
            }
            result++;
            preDay[t] = result;
        }

        return result;
    }
};