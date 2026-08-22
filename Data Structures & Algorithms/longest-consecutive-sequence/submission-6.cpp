class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hs(nums.begin(), nums.end());
        int maxi = 0;
        for(auto num: hs){
            if(hs.find(num - 1) == hs.end()){
                int curr = num;
                int count = 1; 
                while(hs.find(curr+1) != hs.end()) {
                    curr++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
