class Solution {
public:
    set<pair<int,int>>pacific;
    set<pair<int,int>>atlantic;

    void dfs(int i, int j, bool isPacific, int prevHeight, vector<vector<int>>&heights){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || heights[i][j] < prevHeight){
            return;
        }

        if(isPacific){
            if(pacific.find({i,j}) != pacific.end()) return;
            pacific.insert({i,j});
        }else{
            if(atlantic.find({i,j}) != atlantic.end()) return;
            atlantic.insert({i,j});
        }

        const int dir[5] = {0,1,0,-1,0};
        for(int k = 0; k < 4; ++k){
            int ni = i + dir[k];
            int nj = j + dir[k+1];
            dfs(ni,nj,isPacific,heights[i][j],heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>>result;

        for(int i=0; i<cols; ++i){
            dfs(0,i,true,heights[0][i], heights);
            dfs(rows-1,i,false,heights[rows-1][i], heights);
        }

        for(int i=0; i<rows; ++i){
            dfs(i,0,true,heights[i][0], heights);
            dfs(i,cols-1,false,heights[i][cols-1], heights);
        }

        for(auto [r,c]: pacific){
            if(atlantic.find({r,c}) != atlantic.end()){
                result.push_back({r,c});
            }
        }
        return result;
    }
};
