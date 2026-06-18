class Solution {
public:
    void helper(int i,int j,vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == 'Y'){
            return;
        }
        board[i][j] = 'Y';
        helper(i,j+1,board);
        helper(i+1,j,board);
        helper(i,j-1,board);
        helper(i-1,j,board);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); ++i){
            helper(i,0,board);
            helper(i,board[0].size()-1, board);
        }

        for(int j=0; j<board[0].size(); ++j){
            helper(0,j,board);
            helper(board.size()-1,j,board);
        }

        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }

    }
};
