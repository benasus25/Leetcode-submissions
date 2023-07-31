class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>&dp, string &s1,string &s2){
        if(i==s1.size()and j==s2.size())return 0;
        if(i==s1.size())return dp[i][j] = s2[j] + solve(i,j+1,dp,s1,s2);
        else if(j==s2.size())return dp[i][j] = s1[i] + solve(i+1,j,dp,s1,s2);
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j] = solve(i+1,j+1,dp,s1,s2);
        else{
            return dp[i][j] = min(s2[j]+solve(i,j+1,dp,s1,s2),s1[i]+solve(i+1,j,dp,s1,s2));
        }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(),m= s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,dp,s1,s2);
    }
};