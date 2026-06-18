class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        unordered_set<int> HS(nums.begin() , nums.end());
        int currnum;
        int currseq;
        for(auto num : nums){
            if(HS.find(num - 1) != HS.end()) continue;
                currnum = num;
                currseq = 1;

            while(HS.find(currnum + 1) != HS.end()){
                currnum++;
                currseq++;
            }

            maxi = max(currseq , maxi);
        }

        return maxi;
    }
};
