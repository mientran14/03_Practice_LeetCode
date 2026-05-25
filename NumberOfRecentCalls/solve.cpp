class RecentCounter {
public:
    queue<int> request;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        request.push(t);
        while(!request.empty() && request.front() < t - 3000) {
            request.pop();
        }
        return request.size(); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */