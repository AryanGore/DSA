class Solution {
public:
    bool isPalindrome(string s) {
        string copyofs = "";
        transform(s.begin() , s.end() , s.begin() , ::tolower);
        for(int i=0 ; i<s.size() ; ++i){
            if(s[i] == ' ') continue;
            if(!isalnum(s[i])) continue;
            copyofs += s[i];
        }

        int i=0 , j = copyofs.size()-1;
        while(i<=j){
            if(copyofs[i] != copyofs[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
