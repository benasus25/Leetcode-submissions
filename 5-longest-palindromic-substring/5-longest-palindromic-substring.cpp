class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(),start = 0, len  =1;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]= true;
                start = i;
                len = 2;
            }
        }
        for(int j=2;j<n;j++){
            for(int i=0;i<n-j;i++){
                if(s[i]==s[i+j]&&dp[i+1][i+j-1]){
                    dp[i][i+j]=true;
                    start = i;
                    len = j+1;
                }
            }
        }
        return s.substr(start,len);
    }
};