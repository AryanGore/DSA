class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto x : nums){
            freq[x]++;
        }
        vector<vector<int>>vuckets(nums.size()+1);

        for(auto [num , count] : freq){
            vuckets[count].push_back(num);
        }

        vector<int>window = {};
        // window.resize(k);
        for(int i=vuckets.size()-1 ; i>=0 ; --i){
            for(auto it : vuckets[i]){
                if(window.size() < k && vuckets[i].size() > 0){
                    window.push_back(it);
                }
            }
            
        }

        return window;
    }
};
