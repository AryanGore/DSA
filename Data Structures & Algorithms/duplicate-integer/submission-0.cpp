class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>numscopy;
        for(int i=0 ; i<nums.size() ; ++i){
            if(numscopy.find(nums[i]) != numscopy.end()){
                return true;
            }
            numscopy.insert(nums[i]);
        }

        return false;
    }
};