class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>st;
        vector<int>ans;
        for(int i=0; i<nums.size(); ++i){
            int diff = target - nums[i];
            if(st.find(diff) != st.end()){
                if(i<= st[diff]){
                    ans.push_back(i);
                    ans.push_back(st[diff]);
                }else{
                    ans.push_back(st[diff]);
                    ans.push_back(i);
                }

                return ans;
            }

            st[nums[i]] = i;
        }

        return {};
    }
};
