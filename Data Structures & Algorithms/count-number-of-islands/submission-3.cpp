class Solution {
public:
    int maxCount = 0;
    void helper(int i, int j, vector<vector<char>>&grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()|| grid[i][j] == '*' ||grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '*';
        helper(i,j+1,grid);
        helper(i+1,j,grid);
        helper(i,j-1,grid);
        helper(i-1,j,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0; i<grid.size();++i){
            for(int j=0; j < grid[0].size();++j){
                if(grid[i][j] == '1'){
                    helper(i,j,grid);
                    maxCount++;
                }
            }
        }
        return maxCount;
    }
};
