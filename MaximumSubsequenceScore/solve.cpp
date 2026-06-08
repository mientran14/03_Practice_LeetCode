class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> p(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            p[i] = {nums2[i], nums1[i]};
        }
        sort(p.rbegin(), p.rend());
        
        long long result = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (auto [v2, v1] : p) {
            sum += v1;
            minHeap.push(v1);
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                result = max(result, sum * v2);
            }
        }
        return result;
    }
};