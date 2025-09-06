class MinStack {
public:
    stack<int>mainStack;
    stack<int>minStack;
    MinStack() {
        while(!minStack.empty())
            minStack.pop();
        
        while(!mainStack.empty())
            mainStack.pop();
    }
    
    void push(int val) {
        if(minStack.empty())
            minStack.push(val);
        
        else if(val <= minStack.top())
            minStack.push(val);
        
        mainStack.push(val);
    }
    
    void pop() {
        if(!mainStack.empty()){
            int val = mainStack.top();
            mainStack.pop();

            if(minStack.top() == val)
                minStack.pop();
        }

    }
    
    int top() {
        if(!mainStack.empty())  
            return mainStack.top();
        
        return -1;
    }
    
    int getMin() {
        if(!minStack.empty())
            return minStack.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */