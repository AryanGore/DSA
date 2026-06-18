class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>result(temp.size(), 0);
        stack<int>stk;
        // stk.push(temp.size()-1);
        for(int i = temp.size()-1; i>=0; --i){
            while(!stk.empty() && temp[i] >= temp[stk.top()]) {
                stk.pop();
            }  
            if(!stk.empty()) result[i] = stk.top() - i;
            stk.push(i);
        }

        return result;
    }
};
