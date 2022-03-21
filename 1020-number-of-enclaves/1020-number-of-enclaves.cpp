class Solution {
public:
    
    void helper(vector<vector<int>>&grid, int i, int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1)return;
        grid[i][j]=2;
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
    int n= grid.size();
    int m = grid[0].size();
    for(int i =0;i<n;i++){
        if(grid[i][0]){
            helper(grid,i,0);
        }
        if(grid[i][m-1]){
            helper(grid,i,m-1);
        }
    }
    for(int i=0;i<m;i++){
        if(grid[0][i]){
            helper(grid,0,i);
        }
        if(grid[n-1][i]){
            helper(grid, n-1, i);
        }
    }
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            count += grid[i][j]==1?1:0;
        }
    }
    return count;
    }
};