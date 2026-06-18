class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0 ; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        vector<pair<int,int>>dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int count = 0;
        
        while(!q.empty() && fresh > 0){
            int size = q.size();

            while(size--){
                auto [x,y] = q.front();
                q.pop();

                for(auto [dx,dy]: dir){
                    int nx = x + dx;
                    int ny = y + dy;

                    if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                    }

                }
            }

            count++;
        }
        if(fresh > 0) return -1;

        return count;
    }
};
