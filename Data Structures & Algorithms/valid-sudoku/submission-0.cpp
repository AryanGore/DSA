class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> voxes(9);

        for(int i=0 ; i<9 ; ++i){
            for(int j=0 ; j < 9 ; ++j){
                char c = board[i][j];
                if(c == '.') continue;

                if(rows[i].count(c)) return false;
                rows[i].insert(c);
                if(cols[j].count(c)) return false;
                cols[j].insert(c);

                int voxindex = (3 * (i/3)) + (j/3);
                if(voxes[voxindex].count(c)) return false;
                voxes[voxindex].insert(c);

            }
        }

        return true;
    }
};
