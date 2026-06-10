class SmallestInfiniteSet {
public:
    int cur;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	unordered_set<int> inSet;

    SmallestInfiniteSet() : cur(1) {
    }
    
    int popSmallest() {
        if (!minHeap.empty()) {
			int x = minHeap.top();
            minHeap.pop();
            inSet.erase(x);
			return x;
		}
		return cur++;
    }
    
    void addBack(int num) {
        if (num >= cur) return;
		if (inSet.count(num)) return;
		minHeap.push(num);
		inSet.insert(num);
    }
};