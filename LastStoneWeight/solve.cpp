class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // while (stones.size() > 1) {
        //     sort(stones.begin(), stones.end());

        //     int y = stones.back();
        //     stones.pop_back();
        //     int x = stones.back();
        //     stones.pop_back();

        //     if (x != y) {
        //         stones.push_back(y - x);
        //     }
        // }
        // return stones.empty() ? 0 : stones[0];

        
        // Heap
        priority_queue<int> stoneHeap;
        for (int s : stones) {
            stoneHeap.push(s);
        }

        while (stoneHeap.size() > 1) {
            int y = stoneHeap.top();
            stoneHeap.pop();
            int x = stoneHeap.top();
            stoneHeap.pop();
            if (y>x) {
                stoneHeap.push(y-x);
            }
        }
        return stoneHeap.empty() ? 0 : stoneHeap.top();
    }
};
