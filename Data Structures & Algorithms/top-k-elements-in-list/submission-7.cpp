class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num: nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto item: mp){
            pq.push({item.second, item.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            auto item = pq.top();
            ans.push_back(item.second);
            pq.pop();
        }

        return ans;
    }
};
