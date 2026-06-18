class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string>st;
        st.insert("+");
        st.insert("-");
        st.insert("*");
        st.insert("/");

        stack<int>stk;
        int idx = 0;

        while(idx < tokens.size()){
            if(st.find(tokens[idx]) == st.end()){
                int val = stoi(tokens[idx]);
                stk.push(val);
                idx++;
                continue;
            }

            int secondval = stk.top(); stk.pop();
            int firstval = stk.top(); stk.pop();

            if(tokens[idx] == "+"){
                int val = firstval + secondval;
                stk.push(val);
            }else if(tokens[idx] == "-"){
                int val = firstval - secondval;
                stk.push(val);
            }else if(tokens[idx] == "*"){
                int val = firstval * secondval;
                stk.push(val);
            }else{
                int val = firstval / secondval;
                stk.push(val);
            }
            idx++;
        }

        return stk.top();

    }
};
