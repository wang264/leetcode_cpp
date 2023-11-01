#include <stack>


class MinStack {
public:
    std::stack<int> s;
    std::stack<int> sMin;        
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if (sMin.empty() || val<sMin.top()) {
            sMin.push(val);
        } else {
            sMin.push(sMin.top());
        }
        
    }
    
    void pop() {
        s.pop();
        sMin.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return sMin.top();
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