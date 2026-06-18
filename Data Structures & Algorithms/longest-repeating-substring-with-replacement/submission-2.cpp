class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxcount = 0;
        int maxwindow = 0;
        int l = 0, r = 0;

        while(r < s.size()){
            mp[s[r]]++;
            maxcount = max(maxcount, mp[s[r]]);
            if((r-l+1) - maxcount <= k){
                maxwindow = max(maxwindow , r-l+1);
            }else{
                mp[s[l]]--;
                l++;
            }

            r++;
        }

        return maxwindow;
    }
};
