class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>hmap;
        hmap[')'] = '(';
        hmap['}'] = '{';
        hmap[']'] = '[';

        int idx = 0;
        stack<int>stk;
        while(idx < s.size()){
            if(hmap.find(s[idx]) == hmap.end()){
                stk.push(s[idx]);
            }else{
                if(!stk.empty() && hmap[s[idx]] == stk.top()){
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
