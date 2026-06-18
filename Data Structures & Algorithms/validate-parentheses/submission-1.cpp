class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp;
        mp[']'] = '[';
        mp[')'] = '(';
        mp['}'] = '{';

        stack<char>stk;

        for(int i = 0; i < s.size(); ++i){
            if(mp.find(s[i]) == mp.end()){
                stk.push(s[i]);
            }else if(mp.find(s[i]) != mp.end()){
                if(stk.size() > 0 && stk.top() == mp[s[i]]) {
                    stk.pop();
                }
                else return false;
            }
        }

        return stk.empty();
    }
};
