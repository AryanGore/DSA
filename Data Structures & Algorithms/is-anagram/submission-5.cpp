class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>Scount(26, 0);
        vector<int>Tcount(26, 0);

        for(int i=0; i<s.size(); ++i){
            Scount[s[i]-'a']++;
        }

        for(int i=0; i<t.size(); ++i){
            Tcount[t[i]-'a']++;
        }

        if(Scount == Tcount) return true;

        return false;
    }
};
