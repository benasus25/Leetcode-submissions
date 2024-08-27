class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int op = 0;
        if(n > 1 && m > 1){
            for(int i=0;i<n/2;i++){
                for(int j=0;j<m/2;j++){
                    int u = grid[i][j];
                    int v = grid[i][m-j-1];
                    int w = grid[n-i-1][j];
                    int x = grid[n-i-1][m-j-1];
                    int ones = u + v + w + x;
                    if(ones <= 2) op+= ones;
                    else op+= (4 - ones);
                }
            }
        }
        int c = 0;
        int c2 = 0;
        if(n%2){
            for(int j=0;j<m/2;j++){
                if(grid[n/2][j] != grid[n/2][m-j-1]){
                    c++;
                }
                else if(grid[n/2][j]) c2++;
            }
        }
        
        if(m%2){
            for(int j=0;j<n/2;j++){
                if(grid[j][m/2] != grid[n-j-1][m/2]){
                    c++;
                }
                else if(grid[j][m/2]) c2++;
            }
        }
        
        if(c2%2 && c==0) c+= 2;
        if(n%2 && m%2) c+= grid[n/2][m/2];
        return op + c;
    }
};