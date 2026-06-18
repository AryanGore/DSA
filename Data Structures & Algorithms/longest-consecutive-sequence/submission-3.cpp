class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        if(nums.size() == 0) return 0;
        unordered_set<int>visited(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); ++i){
            int count = 0;
            int currNum = nums[i];
            while(visited.find(currNum+1) != visited.end()){
                count++;
                currNum++;
            }
            longest = max(longest, count);
        }

        return longest+1;
    }
};
