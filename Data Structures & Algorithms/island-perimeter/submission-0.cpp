class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& grid, int& perimeter){
        if(i<0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            perimeter++;
            return;
        }
        if(grid[i][j] == -1) return;

        grid[i][j] = -1;
        helper(i,j+1,grid,perimeter);
        helper(i+1,j,grid,perimeter);
        helper(i,j-1,grid,perimeter);
        helper(i-1,j,grid,perimeter);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    helper(i,j,grid,perimeter);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};