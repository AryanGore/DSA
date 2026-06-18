class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int longest = INT_MIN;
        unordered_set<int>visited(nums.begin(), nums.end());

        for(auto num: visited){
            if(visited.find(num-1) != visited.end()) continue;
            int count = 1;
            int currNum = num;

            while(visited.find(currNum + 1) != visited.end()){
                count++;
                currNum++;
            }

            longest = max(longest , count);
        }

        return longest;
    }
};
