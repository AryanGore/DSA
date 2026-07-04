class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pref(nums.size(), 0);
        vector<int>suff(nums.size(), 0);
        vector<int>ans(nums.size(), 0);

        pref[0] = 1; suff[nums.size()-1] = 1;
        for(int i=1; i < nums.size(); ++i){
            pref[i] = pref[i-1] * nums[i-1];
        }

        for(int i=nums.size()-2; i >= 0; --i){
            suff[i] = suff[i+1] * nums[i+1];
            ans[i] = suff[i]*pref[i];
        }

        ans[nums.size()-1] = pref[nums.size()-1] * suff[nums.size()-1];

        return ans;

    }
};
