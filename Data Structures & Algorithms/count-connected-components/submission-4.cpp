class Solution {
public:
    void dfs(int node, vector<bool>&visited, unordered_map<int,vector<int>>&adjlist){
        if(visited[node]) return;
        visited[node] = true;

        for(auto ele: adjlist[node]){
            if(!visited[ele]) dfs(ele, visited, adjlist);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adjlist;
        vector<bool>visited(n, false);
        for(auto edge: edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        int connected = 0;
        for(int i=0; i<n; ++i){
            if(!visited[i]) {
                dfs(i,visited,adjlist);
                connected++;
            }
        }
        return connected;
    }
};
