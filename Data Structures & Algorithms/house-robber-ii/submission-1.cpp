class Solution {
public:
    int getval(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        
        vector<int>dp(nums.size(), -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); ++i){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[nums.size() - 1];
    }

    int rob(vector<int>& nums) {
        vector<int>temp1, temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i=0; i<n; ++i){
            if(i!=0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(getval(temp1), getval(temp2)); 
    }
};
