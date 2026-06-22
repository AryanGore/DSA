class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num : nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto record: mp){
            pq.push({record.second, record.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            auto vec = pq.top();
            ans.push_back(vec.second);
            pq.pop();
        }

        return ans;

    }
};
