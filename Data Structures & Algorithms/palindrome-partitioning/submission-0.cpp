class Solution {
public:
    vector<vector<string>>finalans;
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l <= r){
            if(s[l++] != s[r--]) return false;
        }

        return true;
    }

    void getParts(string s, vector<string>&temp){
        if(s.size() == 0){
            finalans.push_back(temp);
            return;
        }
        for(int i=0; i<s.size(); ++i){
            string part = s.substr(0,i+1);
            if(isPalindrome(part)){
                temp.push_back(part);
                getParts(s.substr(i+1), temp);
                temp.pop_back();
            }        
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        getParts(s,temp);
        return finalans;
    }
};
