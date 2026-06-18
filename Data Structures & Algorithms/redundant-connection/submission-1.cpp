class Solution {
public:
    vector<vector<int>>ans;
    unordered_map<int,vector<int>>adj;
    bool helper(int curr, int u, int v, vector<int>& visited){
        if(curr == v){
            return true;
        }

        visited[curr] = 1;
        for(auto x: adj[curr]){
            if(!visited[x]){
               if(helper(x,u,v,visited)){
                  return true;
               }
            }
            
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        for(auto vec: edges){
            vector<int>visited(edges.size()+1, 0);
            int u = vec[0];
            int v = vec[1];
            if(adj.count(u) && adj.count(v) && helper(u,u,v,visited)){
                return {u,v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
