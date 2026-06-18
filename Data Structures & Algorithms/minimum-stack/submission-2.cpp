class MinStack {
    vector<int>stk;
    vector<int>minstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minstk.size() == 0 || val <= minstk.back()) minstk.push_back(val);
        stk.push_back(val);
    }
    
    void pop() {
        if(stk.back() == minstk.back()) {
            minstk.pop_back();
        }
        stk.pop_back();

    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minstk.back();
    }
};
