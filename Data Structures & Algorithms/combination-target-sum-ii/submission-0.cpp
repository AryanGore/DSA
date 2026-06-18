class Solution {
public:
    vector<vector<int>>finalans;
    void helper(int i, vector<int>&nums , vector<int>&temp, int target){
        if(target == 0){
           finalans.push_back(temp);
        }
        
        for(int j = i; j<nums.size(); ++j){
            if(j>i && nums[j] == nums[j-1]) continue;
            if(target - nums[j] < 0) break;
            temp.push_back(nums[j]);
            helper(j+1, nums, temp, target - nums[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        helper(0, candidates, temp, target);
        return finalans; 
    }
};
