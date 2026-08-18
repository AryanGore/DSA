class Solution {
public:
    void dfs(int idx , vector<int>&nums,vector<bool>&isused, vector<int>&temp, vector<vector<int>>&finalans){
        if(idx == nums.size()) {
            finalans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); ++i){

            if(isused[i]) continue;

            isused[i] = true;
            temp.push_back(nums[i]);

            dfs(idx+1,nums,isused,temp,finalans);

            temp.pop_back();
            isused[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalans;
        vector<int>temp;
        vector<bool>isused(nums.size(), false);
        int idx = 0;
        dfs(0,nums,isused,temp,finalans);
        return finalans;
    }
};
