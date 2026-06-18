class Solution {
public:
    vector<int> temp;
    void subsetBuilder(vector<vector<int>>&ans , vector<int>nums, int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        subsetBuilder(ans, nums, i+1);
        temp.pop_back();
        subsetBuilder(ans, nums, i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>finalans;
        // int i = 0;
        subsetBuilder(finalans, nums, 0);
        return finalans;
    }
};
