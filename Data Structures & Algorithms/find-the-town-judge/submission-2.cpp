class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>>trustlist;
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);

        for(auto vec: trust){
            trustlist[vec[0]].push_back(vec[1]);
        }

        for(auto per: trustlist){
            outdegree[per.first] = per.second.size();
            for(auto item: per.second){
                indegree[item]++;
            }
        }

        for(int i=1; i<n+1; ++i){
            if(indegree[i] == n-1 && outdegree[i] == 0) return i;
        }
        
        return -1;
    }
};