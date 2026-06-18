class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> STR;
        
        for(auto s: strs){
            string currs = s;
            sort(currs.begin() , currs.end());
            STR[currs].push_back(s);
        }

        for(auto pair : STR){
            ans.push_back(pair.second);
        }

        return ans;        
    }
};
