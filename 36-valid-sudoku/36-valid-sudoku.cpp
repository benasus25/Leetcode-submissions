class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<set<int>>row(9),column(9),block(9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')continue;
            int c = board[i][j]-'0';
            int ind = (i/3)*3+ (j/3);
            if(row[i].count(c)||column[j].count(c)||block[ind].count(c))return false;
            else{
                row[i].insert(c);
                column[j].insert(c);
                block[ind].insert(c);
            }
        }
    }
    return true;
    }
};