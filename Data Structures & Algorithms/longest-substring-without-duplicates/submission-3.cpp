class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxcount = INT_MIN;
        int count = 0;
        int lt = 0;
        int rt = 0;

        unordered_set<char>hs;

        while(rt < s.size()){
            if(hs.find(s[rt]) != hs.end()){
                hs.erase(s[lt++]);
                count--;
            }else{
                count++;
                hs.insert(s[rt++]);
                maxcount = max(maxcount , count);

            }
        }

        return maxcount == INT_MIN ? 0 : maxcount;
    }
};
