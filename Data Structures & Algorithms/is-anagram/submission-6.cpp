class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>S(26,0);
        vector<int>T(26,0);

        for(auto ch: s){
            S[ch - 'a']++;
        }

        for(auto ch: t){
            T[ch - 'a']++;
        }

        return S == T ? true : false;
    }
};
