class Solution {
public:
    bool isFound = false;
    void dfs(int i, int j, int idx, vector<vector<char>>& board, string& word){
        if(idx == word.size()){
            isFound = true;
            return;
        }

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*'){
            return;
        }

        if(board[i][j] != word[idx]) return;
        idx++;
        board[i][j] = '*';
        dfs(i, j+1, idx, board, word);
        dfs(i+1, j, idx, board, word);
        dfs(i, j-1, idx, board, word);
        dfs(i-1, j, idx, board, word);
        board[i][j] = word[idx-1];
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int idx = 0;
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j] == word[idx]){
                    dfs(i,j,idx,board,word);
                    if(isFound) return true;
                }
            }
        }

        return false;
    }
};
