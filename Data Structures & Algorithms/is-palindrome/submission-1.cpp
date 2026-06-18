class Solution {
public:
    bool isPalindrome1(string str){
        int l = 0;
        int r = str.size()-1;

        while(l<=r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    bool isPalindrome(string s) {
        string copyofs = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for(int i=0; i<s.size(); ++i){
            if(s[i] == ' ') continue;
            if(!isalnum(s[i])) continue;
            copyofs+=s[i];
        }

        return isPalindrome1(copyofs);
    }
};
