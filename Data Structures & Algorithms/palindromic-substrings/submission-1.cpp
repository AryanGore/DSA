class Solution {
public:
    int res = 0;
    void palindromeCount(string s, int l , int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            res++;
            l--;
            r++;
        }        
    }
    int countSubstrings(string s) {
        for(int i =0; i<s.size(); ++i){
            palindromeCount(s,i,i);
            palindromeCount(s,i,i+1);
        }
        return res;
    }
};