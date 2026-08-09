class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hs;
        for(int i=0; i<nums.size(); ++i){
            if(hs.find(target - nums[i]) != hs.end()) return {hs[target - nums[i]], i};
            hs[nums[i]] = i;
        }

        return {};
    }
};
