class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>countAllowed(26,false);

        for(int i=0; i<allowed.size(); ++i){
            countAllowed[allowed[i] - 'a'] = true;
        }
        int consistent = 0;
        for(auto word: words){
            bool ok = true;
            for(int i=0; i<word.size(); ++i){
                if(!countAllowed[word[i] - 'a']){
                    ok = false;
                    break;
                }
            }
            if(ok) consistent++;
        }

        return consistent;
    }
};