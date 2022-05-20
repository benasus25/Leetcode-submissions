class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size();
        int dp[n][m],num=1;
        for(int i=0;i<n;i++){
            if(grid[i][0])num =0;
            dp[i][0]=num;
        }
        num=1;
        for(int i=0;i<m;i++){
            if(grid[0][i])num=0;
            dp[0][i]=num;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j])dp[i][j]=0;
                else dp[i][j]= dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};