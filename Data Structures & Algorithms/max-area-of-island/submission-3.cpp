class Solution {
public:
    int maxCount = 0;
    void helper(int i, int j, vector<vector<int>>&grid, int&count){
        if(i<0 || i >= grid.size() || j <0 || j >= grid[0].size() || grid[i][j] == 0){
            // maxCount = max(maxCount, count);
            return;
        }
        count++;
        grid[i][j] = 0;
        helper(i,j+1,grid,count);
        helper(i+1,j,grid,count);
        helper(i,j-1,grid,count);
        helper(i-1,j,grid,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                count = 0;
                if(grid[i][j] == 1) helper(i,j,grid,count);
                maxCount = max(maxCount , count);
            }
        }
        return maxCount;
    }
};
