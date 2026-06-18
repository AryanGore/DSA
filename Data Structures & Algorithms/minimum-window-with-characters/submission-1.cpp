class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, minLen = INT_MAX, startIndex = -1, count = 0;
        unordered_map<char,int>mp;

        for(int i=0; i<t.size(); ++i){
            mp[t[i]]++;
        }

        while(r < s.size()){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startIndex = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen); 
    }
};
