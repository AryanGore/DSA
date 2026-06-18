class Solution {
public:
    vector<vector<int>> result;
    void helper(int i, vector<int>&nums, vector<int>&temp){
        if(i== nums.size()){
            result.push_back(temp);
            return;
        }
        result.push_back(temp);
        for(int j=i ; j<nums.size(); ++j){
            if(j>i && nums[j] == nums[j-1]) continue;
            temp.push_back(nums[j]);
            helper(j+1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
       // result.push_back(temp);
        helper(0, nums, temp);
        return result;
    }
};
