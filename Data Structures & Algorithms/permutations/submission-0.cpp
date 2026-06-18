class Solution {
public:
    vector<vector<int>>result;
    void helper(vector<bool>&used, vector<int>&nums, vector<int>temp){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i =0; i<nums.size(); ++i){
            if(used[i]) continue;

            temp.push_back(nums[i]);
            used[i] = true;
            helper(used, nums, temp);
            used[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        helper(used, nums, temp);
        return result;
    }
};
