class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>hmap; //value, key
        for(int i=0; i<nums.size(); ++i){
            if(hmap.find(nums[i]) != hmap.end()){
                if(abs(i - hmap[nums[i]]) <= k){
                    return true;
                }
            }
            hmap[nums[i]] = i;
        }
        return false;
    }
};