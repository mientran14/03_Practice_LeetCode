class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxHeap;

        for (int n : nums) {
            maxHeap.push(n);
        }
        
        int max1 = maxHeap.top();
        maxHeap.pop();
        int max2 = maxHeap.top();
        maxHeap.pop();

        return (max1-1)*(max2-1);
    }
};