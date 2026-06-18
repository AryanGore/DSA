class Solution {
public:
    void helper(int val, map<int,vector<int>>& premap, vector<int>& visited){
        if(visited[val] == 1){
            return;
        }
        visited[val] = 1;
        for(auto x: premap[val]){
            helper(x, premap, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>premap;

        for(auto vec: edges){
            premap[vec[0]].push_back(vec[1]);
            premap[vec[1]].push_back(vec[0]);
        }

        vector<int>visited(n, 0);

        int count = 0;
        
        for(int i=0; i<n; ++i){
            if(visited[i] == 0){
                helper(i,premap,visited);
                count++;
            }
        }

        return count;
    }
};
