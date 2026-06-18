class Solution {
public:
    vector<vector<int>>finalans;
    void comHelper(int i , vector<int>&nums, int target, int& currsum, vector<int>&temp){
        // if(i == nums.size()) return;
            if(currsum == target){
                finalans.push_back(temp);
                return; 
            } 

            if(currsum > target) return;

        for(int j = i; j<nums.size(); ++j){
            temp.push_back(nums[j]);
            currsum += nums[j];
            comHelper(j, nums, target, currsum, temp);
            currsum -= nums[j];
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        vector<int> temp;
        int currsum = 0;
        comHelper(0, nums, target, currsum, temp);
        return finalans;
    }
};
