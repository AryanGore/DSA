class MinStack {
    vector<int>stk;
    vector<int>minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        if(minStk.empty() || val <= minStk.back()){
            minStk.push_back(val);
        }
    }
    
    void pop() {
        if(minStk.back() == stk.back()){
            minStk.pop_back();
        }
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};
