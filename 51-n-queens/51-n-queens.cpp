class Solution {
public:
    
    vector<vector<string>>matrix;
    
    bool safe(vector<string>&board,int row, int idx){
        for(int i=row;i>=0;i--){
            if(board[i][idx]=='Q')return false;
        }
        for(int j=idx,i=row;j>=0&&i>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int j=idx,i=row;j<board.size()&&i>=0;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    
    void helper(vector<string>&board, int row){
        if(row==board.size()){
            matrix.push_back(board);
            return;
        }
        for(int i =0;i<board.size();i++){
            if(safe(board,row,i)){
                board[row][i] = 'Q';
                helper(board,row+1);
                board[row][i] = '.';
            }
        }  
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        helper(board,0);
        return matrix;
    }
};