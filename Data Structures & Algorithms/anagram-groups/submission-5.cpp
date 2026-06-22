class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>strmap;
        for(auto str: strs){
            string copyOfStr = str;
            sort(copyOfStr.begin(), copyOfStr.end());
            strmap[copyOfStr].push_back(str);
        }

        vector<vector<string>> result;
        for(auto vec: strmap){
            result.push_back(vec.second);
        }

        return result;
    }
};
