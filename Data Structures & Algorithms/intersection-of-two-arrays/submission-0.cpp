class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>hs;
        for(auto num: nums1){
            hs.insert(num);
        }
        vector<int> ans;
        for(auto num: nums2){
            if(hs.find(num) != hs.end()){
                ans.push_back(num);
                hs.erase(num);
            }
        }

        return ans;
    }
};