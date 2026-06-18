class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>numscopy;
        for(int i= 0 ; i< nums.size() ; ++i){
            numscopy[nums[i]] = i;
        }

        for(int i=0 ; i< nums.size() ; ++i){
            if(numscopy.find(target - nums[i]) != numscopy.end()){
                if(i == numscopy[target - nums[i]]) continue;
                return {i,numscopy[target - nums[i]]};
            }
        }

        return {};
    }
};
