class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size(), 0);
        stack<int>stk;

        for(int i = temperatures.size()-1; i>=0; --i){
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
            if(!stk.empty()) result[i] = stk.top() - i;
            stk.push(i);
        }

        return result;

    }
};
