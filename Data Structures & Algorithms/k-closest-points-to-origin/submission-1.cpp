class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxheap;
        for(auto& coordinate: points){
            int x = coordinate[0];
            int y = coordinate[1];
            int ans = x*x + y*y;

            maxheap.push({ ans, {x,y}});
            if(maxheap.size() > k) maxheap.pop();
        }

        vector<vector<int>>finalans;
        while(!maxheap.empty()){
            auto entry = maxheap.top();
            finalans.push_back({entry.second.first, entry.second.second});
            maxheap.pop();
        }

        return finalans;
    }
};
