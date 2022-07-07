class Solution {
public:
    
    bool helper(string s, string r, string t, int i, int j, int k, vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s.length()&&j==r.length()&&k==t.length())return true;
        bool res = false;
        if(i!=s.length()){
            if(s[i]==t[k]){
                res |= helper(s,r,t,i+1,j,k+1,dp);
            }
        }
        if(j!=r.length()){
            if(r[j]==t[k]){
                res |= helper(s,r,t,i,j+1,k+1,dp);
            }
        }
        return dp[i][j]= res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(),m = s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s1,s2,s3,0,0,0,dp);
    }
};