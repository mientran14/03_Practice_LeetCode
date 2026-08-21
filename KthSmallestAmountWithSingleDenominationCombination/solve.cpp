class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // TLE 522/561 testcases passed
        priority_queue<pair<long long, long long>, 
                       vector<pair<long long, long long>>, 
                       greater<pair<long long, long long>>> pq;

        for (int c : coins) pq.push({c, c});

        long long lastVal = 0;
        int count = 0;

        while (!pq.empty()) {
            long long val = pq.top().first;
            long long coin = pq.top().second;
            pq.pop();

            if (val != lastVal) {
                count++;
                lastVal = val;
                
                if (count == k) return val;
            }

            pq.push({val + coin, coin});
        }

        return -1;
    }
};