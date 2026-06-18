class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int> >pq;
        unordered_map<int,int>mp;
        vector<int>ans;

        for(auto x: nums){
            mp[x]++;
        }

        for(auto x: mp){
            pq.push({ x.second, x.first }); //first: nums value frequency, second : nums value.
        }

        for(int i=0; i<k; ++i){
            if(pq.empty()) break;
            int val = pq.top().second;
            pq.pop();
            ans.push_back(val);
        }

        return ans;
    }
};
