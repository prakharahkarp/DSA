class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col){
        
//         check in current row
        for(int i = 0; i < col; i++){
            if(board[row][i] == 'Q') return false;
        }
        
        
//         check in upper diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        
//         check in lower diagonal
        for(int i = row + 1, j = col - 1; i < board.size() && j >= 0; i++, j--){
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void generateNQueens(vector<vector<string>>& ans, vector<string>& board, int col){
        int n = board.size();
        
        if(col == n){
            ans.push_back(board);
            return ;
        }
        
        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                generateNQueens(ans, board, col + 1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string str(n, '.');
        vector<string> board(n, str);
        generateNQueens(ans, board, 0);
        return ans;
        // return {row};
    }
};