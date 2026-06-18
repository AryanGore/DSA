class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int>mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        int idx = 0;
        stack<int>stk;
        while(idx < s.size()){
            if(mp.find(s[idx]) == mp.end()){
                stk.push(s[idx]);
            }else{
                if(!stk.empty() && mp[s[idx]] == stk.top()){
                    stk.pop();
                }else{
                    return false;
                }
            }

            idx++;
        }

        return stk.size() == 0 ? true : false;
    }
};
