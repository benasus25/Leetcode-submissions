class Solution {
public:
    
    bool issafe(char c, vector<vector<char>>&board, int row, int col){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==c)return false;
        }
        for(int j=0;j<board[0].size();j++){
            if(board[row][j]==c)return false;
        }
        for(int i=0;i<board.size();i++){
            if(board[3*(row/3)+i/3][3*(col/3)+(i%3)]==c)return false;
        }
        return true;
    }
    
    bool helper(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c = '1';c<='9';c++){
                        if(issafe(c,board,i,j)){
                            board[i][j]=c;
                            if(helper(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};