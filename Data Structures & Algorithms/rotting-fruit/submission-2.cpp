class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        const int dir[5] = {0, 1, 0, -1, 0};
        int minute = 0;
        
        while(!q.empty() && fresh > 0){
            int size = q.size();

            while(size--){
                auto [x,y] = q.front();
                q.pop();

                for(int i=0; i<4; ++i){
                    int nx = x + dir[i];
                    int ny = y + dir[i+1];
                    if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            minute++;
        }

        return fresh > 0 ? -1 : minute;

    }
};
