class MinStack {
public:
    stack<int> myStack;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push(val);

        if(minStack.empty()){
            minStack.push(val);
        }else if(val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        // Update min value if removing the same
        if(myStack.top() == minStack.top()){
            minStack.pop();
        }
        myStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
