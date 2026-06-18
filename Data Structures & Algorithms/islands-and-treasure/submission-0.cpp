class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& grid, int count){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1){
            return;
        }

        if(count > grid[i][j]) return;
        grid[i][j] = count;
        
        helper(i,j+1,grid,count+1);
        helper(i+1,j,grid,count+1);
        helper(i,j-1,grid,count+1);
        helper(i-1,j,grid,count+1);

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    helper(i,j,grid,0);
                }
            }
        }
    }
};
