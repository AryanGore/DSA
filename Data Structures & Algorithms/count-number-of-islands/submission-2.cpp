class Solution {
public:
    int Count = 0;
    void Helper(int i, int j, vector<vector<char>>& grid){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';

        Helper(i,j+1,grid);
        Helper(i+1,j,grid);
        Helper(i,j-1,grid);
        Helper(i-1,j,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i<grid.size(); ++i){
            for(int j = 0; j<grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    Helper(i,j, grid);
                    Count++;
                }
            }
        }
        return Count;
    }
};
