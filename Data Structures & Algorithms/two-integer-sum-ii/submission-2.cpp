class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans ;
        for(int i=0; i<nums.size(); ++i){
            int leftsum = target - nums[i];
            
            int s=0;
            int e=nums.size()-1;
            int mid;
            while(s<=e){
                mid = s + (e-s)/2;
                if(nums[mid] ==leftsum){
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                }else if(nums[mid] < leftsum){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }

        }

        return {};
    }
};
