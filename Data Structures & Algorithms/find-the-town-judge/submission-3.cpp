class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>>adjlist;
        for(auto vec: trust){
            adjlist[vec[0]].push_back(vec[1]);
        }
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
    
        for(auto x: adjlist){
            outdegree[x.first] = x.second.size();
            for(auto node: x.second){
                indegree[node]++;
            }
        }

        for(int i=1; i<=n; ++i){
            if(indegree[i] == n-1 && outdegree[i] == 0) return i;
        }
        return -1;
    }
};