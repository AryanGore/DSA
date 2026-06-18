class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int counterSum = 0;

        for(int i=0 ; i < nums.size()-2 ; ++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            left = i+1;
            right = nums.size() - 1;
            counterSum = -nums[i];
            while(left < right) {
                if(nums[left] + nums[right] == counterSum){
                    ans.push_back({nums[i] , nums[left] , nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;

                }else if(nums[left] + nums[right] < counterSum){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return ans;
    }
};
