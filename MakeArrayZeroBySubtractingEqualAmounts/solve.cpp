class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int x : nums) {
            if (x > 0) minHeap.push(x);
        }

        int result = 0, num = 0;
        while (!minHeap.empty()) {
            int tmp = minHeap.top() - num;
            if (tmp != 0) {
                num += tmp;
                result++;
            }
            minHeap.pop();
        }
        return result;
    }
};
