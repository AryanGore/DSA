class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string>> groupgrams;
        for(auto s : strs){
            string key = s;
            sort(key.begin(),key.end());
            groupgrams[key].push_back(s);
        }

        vector<vector<string>> finalans;
        for(auto& pair : groupgrams){
            finalans.push_back(pair.second);
        }

        return finalans;
    }
};
