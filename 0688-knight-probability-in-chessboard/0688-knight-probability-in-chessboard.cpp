class Solution {
public:
    
    double dp[26][26][101];
    int dx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
    
    double find(int s, int e, int n, int k){
        if(s>=n || e>=n||s<0||e<0)return 0;
        if(k==0)return 1;
        if(dp[s][e][k]!=0)return dp[s][e][k];
        double res = 0;
        for(int i =0;i<8;i++){
            
            res+=(find(s+dx[i],e+dy[i],n,k-1));
        }
        return dp[s][e][k] += ( res/8.0);
    }
    
    double knightProbability(int n, int k, int row, int col) {
        memset(dp,0,sizeof(dp));
        return find(row,col,n,k);
    }
};