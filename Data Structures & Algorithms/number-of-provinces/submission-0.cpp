class Solution {
public:
    void dfs(int node, vector<bool>& visited, const vector<vector<int>>&isConnected){
        if(visited[node]) return;
        visited[node] = true;

        for(int i=0; i<isConnected.size(); ++i){
            if(!visited[i] && isConnected[node][i] == 1) dfs(i,visited,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(), false);
        int provinces = 0;
        for(int i=0; i<isConnected.size(); ++i){
            if(!visited[i]){
                dfs(i,visited, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};