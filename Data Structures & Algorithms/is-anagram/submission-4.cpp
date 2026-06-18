class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>s_mp(26,0);
        vector<int>t_mp(26,0);

        for(auto x: s){
            s_mp[x-'a']++;
        }

        for(auto x: t){
            t_mp[x-'a']++;
        }

        if(s_mp == t_mp){
            return true;
        }

        return false;
    }
};
