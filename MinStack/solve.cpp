class MinStack {
public:
    stack<int> dataS;
    stack<int> minS;

    MinStack() {
        // initializes empty
    }
    
    void push(int val) {
        dataS.push(val);
        if(minS.empty() || val <= minS.top()) minS.push(val);
    }
    
    void pop() {
        if(dataS.top() == minS.top()) minS.pop();
        dataS.pop();
    }
    
    int top() {
        return dataS.top();
        
    }
    
    int getMin() {
        return minS.top();
    }
};
