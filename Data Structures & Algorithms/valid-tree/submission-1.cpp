class Solution {
public:
    bool isValid = true;

    void helper(int val ,int parent , map<int,vector<int>>&adjList,vector<int>&visited){
        if(visited[val] == 1){
            isValid = false;
            return;  
        }
        visited[val] = 1;
        for(auto x: adjList[val]){
            if(x == parent) continue;
            helper(x,val,adjList,visited);
        }

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>adjList;
        vector<int>visited(n, 0);
        for(auto vec: edges){
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
        }
        
        helper(0 ,-1 ,adjList, visited);

        for(int i=0; i<n; ++i){
            if(visited[i] != 1) return false;
        }

        return isValid;

    }
};
