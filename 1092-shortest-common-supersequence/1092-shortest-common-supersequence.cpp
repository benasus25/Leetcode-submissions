class Solution {
public:
    
    string helper(vector<vector<int>>&dp, string s, string r, int n, int m){
        if(n==0)return r.substr(0,m);
        else if(m==0)return s.substr(0,n);
        if(s[n-1]==r[m-1]){
            return helper(dp,s,r,n-1,m-1) + s[n-1];
        }
        else{
            if(dp[n-1][m]<dp[n][m-1]){
                return helper(dp,s,r,n-1,m)+ s[n-1];
            }
            else{
                return helper(dp,s,r,n,m-1) + r[m-1];
            }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(),m = str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else{
                    if(str1[i-1]==str2[j-1]){
                        dp[i][j]= dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
                    }
                }
            }
        }
        return helper(dp,str1,str2,n,m);
    }
};