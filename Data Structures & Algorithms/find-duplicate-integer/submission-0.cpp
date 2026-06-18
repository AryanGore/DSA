class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>visited;
        int ans;
        for(auto x: nums){
            if(visited.find(x) != visited.end()){
                ans = x;
                break;
            }
            visited.insert(x);
        }

        return ans;
    }
};
