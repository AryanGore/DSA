class Solution {
public:
    int maxi = INT_MIN;
    void dfs(int i, int j, int& count, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            // maxi = max(count, maxi);
            return;
        }

        grid[i][j] = 0;
        count++;

        dfs(i,j+1,count,grid);
        dfs(i+1,j,count,grid);
        dfs(i,j-1,count,grid);
        dfs(i-1,j,count,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0 ; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    int count = 0;
                    dfs(i,j,count,grid);
                    maxi = max(maxi, count);
                }
            }
        }

        return maxi == INT_MIN ? 0 : maxi;
    }
};
