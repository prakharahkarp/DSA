class Solution {
public:
    bool DFS(int r, int c, vector<vector<char>>& board, int currInd, string& word){
        
        int m = board.size(), n = board[0].size();
        
        board[r][c] = '$';
        if(currInd == word.size()) return true;
        if(c - 1 >= 0 && board[r][c - 1] == word[currInd] && DFS(r, c - 1, board, currInd + 1, word)) return true;
        else if(c + 1 < n && board[r][c + 1] == word[currInd] && DFS(r, c + 1, board, currInd + 1, word)) return true;
        else if(r - 1 >= 0 && board[r - 1][c] == word[currInd] && DFS(r - 1, c, board, currInd + 1, word)) return true;
        else if(r + 1 < m && board[r + 1][c] == word[currInd] && DFS(r + 1, c, board, currInd + 1, word)) return true;
        board[r][c] = word[currInd - 1];
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(DFS(i, j, board, 1, word)) return true;
                }
            }
        }
        return false;
    }
};