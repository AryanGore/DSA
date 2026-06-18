class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_set<int>visited;
        // int ans;
        // for(auto x: nums){
        //     if(visited.find(x) != visited.end()){
        //         ans = x;
        //         break;
        //     }
        //     visited.insert(x);
        // }

        // return ans;

        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int slow2 = 0;
        while(slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
