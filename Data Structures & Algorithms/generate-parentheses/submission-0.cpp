class Solution {
public:
    vector<string> ans;
    void build(int open, int close, int n, string& temp){
        if(open == n && open == close){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            temp += '(';
            build(open+1, close, n, temp);
            temp.pop_back();
        }

        if(close < open){
            temp += ')';
            build(open, close+1, n, temp);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        build(0,0,n,temp);
        return ans;
    }
};
