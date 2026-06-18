class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>hs;
        for(auto x: nums){
            if(hs.find(x) != hs.end()){
                return true;
            }
            hs.insert(x);
        }

        return false;
    }
};